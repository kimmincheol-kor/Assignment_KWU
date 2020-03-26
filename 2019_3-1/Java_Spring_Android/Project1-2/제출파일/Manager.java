package book;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.*;
import java.util.StringTokenizer;
import java.util.*;

public class Manager {

	BufferedReader fbook;	//input stream ( for BookList.txt, command.txt )
	BufferedReader fcom;	//input stream ( for BookList.txt, command.txt )
	BufferedWriter flog; //output stream  (for log.txt )
	myCollection mycol;
	
	public Manager() throws IOException {
		mycol = new myCollection(); // instance of mycollection
		flog = new BufferedWriter(new FileWriter("log.txt", true)); // open write file 'log.txt'
		fbook = new BufferedReader(new FileReader("BookList.txt")); //  open read file 'BookList.txt'

		String read_booklist = ""; // String, use at read booklist
	
		while( (read_booklist = fbook.readLine()) != null )
		{ // ADD Booklist.txt to my collection
			String [] info_book = read_booklist.split("/");
			BookNode bn = new BookNode(info_book[0], info_book[1]);
			
			mycol.addNode(bn); // add BookNode to mycollection
		}	
	}

	public void run(String cmd) throws IOException{ // Manager run.
		fcom = new BufferedReader(new FileReader(cmd)); // open read file 'command.txt'
		String read_line = null; // String, use at read command
		
		while( ( read_line = fcom.readLine() ) != null  ) { // read command line, and command line is exist
			String [] read_cmd = read_line.split(" ", 2); // divide command by space. read_cmd[0] = command
			
			// command : ADD
			if(read_cmd[0].equals("ADD")) { 
				String [] read_input = read_cmd[1].split("/"); // divide command by '/'
				
				if(read_input.length != 2) // ONLY 2 Strings, Bookname, Author.
					ERROR_LOGGING(100);
				else if(ADD(read_input[0], read_input[1]) == false)
					ERROR_LOGGING(100);
			}
			// command : PRiNT
			else if(read_cmd[0].equals("PRINT")) { 
				if(read_cmd.length != 2)
					ERROR_LOGGING(200);
				else if(read_cmd[1].length() != 2) // ONLY 2 characters, collection name.
					ERROR_LOGGING(200);
				else if(PRINT(read_cmd[1]) == false)
					ERROR_LOGGING(200);
			}
			// command : SEARCH
			else if(read_cmd[0].equals("SEARCH")) { 
				String [] read_input = read_cmd[1].split(" ", 2);// divide command by space, collection name, bookname.
				
				if(read_input[0].length() != 2 || read_input.length != 2) // ONLY 2 characters, collection name, and need bookname.
					ERROR_LOGGING(300);
				else if(SEARCH(read_input[0], read_input[1]) == false)
					ERROR_LOGGING(300);
			}
			// command : UPDATE
			else if(read_cmd[0].equals("UPDATE")) { 
				String [] read_input = read_cmd[1].split("/"); // // divide command by '/', original bookname, update bookname.
				
				if(read_input.length != 2) // ONLY 2 Strings, original bookname, update bookname.
					ERROR_LOGGING(400);
				else if(UPDATE(read_input[0],read_input[1]) == false)
					ERROR_LOGGING(400);
			}
			// command : EXIT
			else if(read_cmd[0].equals("EXIT")) { 
				flog.write("========= " + "EXIT" + " =========\r\n");
				flog.flush();
				flog.write("Success\r\n");
				flog.flush();
				flog.write("=========" + "======" + "=========\r\n\r\n");
				flog.flush();
				break;
			}
			flog.write("\r\n");
			flog.flush();
		}
		fcom.close();
		fbook.close();
		flog.close();
	}
	
	public void ERROR_LOGGING(int er) throws IOException{ // PRINT ERROR MESSAGE
		flog.write("========= " + "ERROR" + " =========\r\n");
		flog.flush();
		flog.write(er + "\r\n");
		flog.flush();
		flog.write("=========" + "=========" + "=======\r\n");
		flog.flush();
	}
	
	// METHOD ADD
	public boolean ADD(String book_name, String writer_name) throws IOException{ 
		BookNode bn = new BookNode(book_name, writer_name); // make booknode.
		
		if(mycol.addNode(bn) == true) { // add BookNode to mycollection, if success,
			flog.write("========== " + "ADD" + " ==========\r\n");
			flog.flush();
			flog.write("+ " + book_name + "/" + writer_name);
			flog.flush();
			flog.write("\r\n========" + "=========" + "========\r\n");
			flog.flush();
			return true;
		}
		else // if fail to add,
			return false;
	}
	
	// METHOD PRINT
	public boolean PRINT(String col) throws IOException{
		if(mycol.num_node == 0) // if booklist is not exist,
			return false;
			
		switch(col) // check collection name.
		{
		case "AL":
		case "LL":
		case "HS":
		case "TS":
		case "HM":
		case "TM":
			flog.write("=========" + " PRINT " + "=========\r\n");
			flog.flush();
			mycol.printNode(col, flog);
			flog.write("========" + "=========" + "========\r\n");
			flog.flush();
			return true;
		default: // not exist that collection name. -> fail
			return false;
		}
	}
	
	// METHOD SEARCH
	public boolean SEARCH(String col, String book_name) throws IOException{
		String result;
		switch(col) // check collection name.
		{
		case "AL":
		case "LL":
		case "HS":
		case "TS":
		case "HM":
		case "TM":
			result = mycol.searchNode(col, book_name); // search bookname and return to result.
			if(result.equals("error")) // return value is "error" -> not exist book -> fail
				return false;
			else { // find book !
				flog.write("========" + "SEARCH" + "========\r\n");
				flog.flush();
				flog.write(result);
				flog.flush();
				flog.write("========" + "========" + "========\r\n");
				flog.flush();
				return true;
			}

		default: // not exist that collection name. -> fail
			return false;
		}
	}
	
	// METHOD UPDATE
	public boolean UPDATE(String ori_book, String upt_book) throws IOException{
		String result;
		result = mycol.updateNode(ori_book, upt_book); // update bookname and return to result.
		if( result.equals("error") == true ) // return value is "error" -> not exist book -> fail
			return false;
		else {
			flog.write("========" + "UPDATE" + "========\r\n");
			flog.flush();
			flog.write(result);
			flog.flush();
			flog.write("========" + "========" + "========\r\n");
			flog.flush();
			return true;
		}
	}

}
