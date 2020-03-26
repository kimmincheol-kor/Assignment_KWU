#include <linux/module.h>
#include <linux/highmem.h>
#include <linux/kallsyms.h>
#include <linux/syscalls.h>
#include <asm/syscall_wrapper.h>
#include <linux/sched/mm.h>

// system call add's table number.
#define __NR_add 549

// store current system call's address
void **syscall_table;

// point read add system call
void *real_add;

__SYSCALL_DEFINEx(1, _os_info, pid_t, pid) // subtitute existing system call to os_info
{
	struct task_struct *p_t; 		// task struct pointer t.
	struct mm_struct *p_mm; 		// mm struct pointer mm.
	struct vm_area_struct *p_mmap; 	// vm area struct pointer p_mmap
	
	char str[100]; // store path of Original File

	int i; // use at while().
	
	char * pname = NULL; // string pointer for path of Original File
	
	p_t = pid_task(find_vpid(pid), PIDTYPE_PID); 	// pointer t => pid's task struct
	p_mm = get_task_mm(p_t); 						// pointer mm => process pid's mm struct
	p_mmap=p_mm->mmap; 								// pointer mmap => mm's vm area struct
	
	printk(KERN_INFO "######### Loaded files of a process 'test(%d)' in VM ##########\n", pid);
	
	while(1) // repeat while exist vm_next of vm_area_struct
	{
		if(p_mmap->vm_file != NULL) // mmap struct has file ?
		{
			i = 0; // reset i
			while(i<100) // repeat 100 times
			{
				str[i] = '\0'; // reset string to NULL
				i++;
			}
			
			// put the full path of the file
			pname = dentry_path_raw(p_mmap->vm_file->f_path.dentry, str, 99);
			
			// print information of process to kernel message
			printk(KERN_INFO "mem[%lx~%lx] data[%lx~%lx] code[%lx~%lx] heap[%lx~%lx] %s",p_mmap->vm_start, p_mmap->vm_end, p_mm->start_data, p_mm->end_data, p_mm->start_code, p_mm->end_code, p_mm->start_brk, p_mm->brk, pname);
		}
		
		if(p_mmap->vm_next == NULL) // not exist next.
			break;
		else // point next mmap
			p_mmap = p_mmap->vm_next;
	}
	
	// use count -1
	mmput(p_mm);
	
	printk(KERN_INFO "###############################################################\n");

	return 0;
}

void make_rw(void *addr) // give permission (read,write authority of *addr's page)
{
	unsigned int level;
	pte_t *pte = lookup_address((u64)addr, &level); // addr in memory, level of the mapping

	if(pte->pte &~ _PAGE_RW) // if no permission,
		pte->pte |= _PAGE_RW; // give that.
}

void make_ro(void *addr) // recover permission (read,write authority of *addr's page)
{
	unsigned int level;
	pte_t *pte = lookup_address((u64)addr, &level); // addr in memory, level of the mapping

	pte->pte = pte->pte &~ _PAGE_RW; // recover permission
}

static int __init wrraping_init(void) { // when module embarked, do it
	printk(KERN_INFO "init_[2015722087]\n"); // print my id

	syscall_table = (void**) kallsyms_lookup_name("sys_call_table"); // find system call table

	make_rw(syscall_table); // give permission

	real_add = syscall_table[__NR_add]; // store current system call address

	syscall_table[__NR_add] = __x64_sys_os_info; // change system call to sys_mul
	
	return 0;
}

static void __exit wrraping_exit(void) { // when module relieve, do it
	printk(KERN_INFO "exit_[2015722087]\n"); // print my id

	syscall_table[__NR_add] = real_add; // recover system call to sys_add

	make_ro(syscall_table); // recover permission
}

module_init(wrraping_init);
module_exit(wrraping_exit);
MODULE_LICENSE("GPL");
