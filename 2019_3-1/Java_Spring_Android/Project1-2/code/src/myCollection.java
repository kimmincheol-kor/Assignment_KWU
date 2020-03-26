package book;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;


public class myCollection {

	//Collectiion
	private ArrayList<BookNode> al; 
	private LinkedList<BookNode> ll;
	private HashSet<BookNode> hs;
	private TreeSet<BookNode> ts;
	private HashMap<String, String> hm;	//Key : title, value : author
	private TreeMap<String, String> tm; //Key : title, value : author
	public int num_node;
	
	public myCollection(){
		al = new ArrayList<BookNode>();
		ll = new LinkedList<BookNode>();
		hs = new HashSet<BookNode>();
		ts = new TreeSet<BookNode>();
		hm = new HashMap<String, String>();
		tm = new TreeMap<String, String>();
		
		num_node = 0;
	}
	
	/*Push method*/
	public boolean addNode(BookNode bn) {
		
		if(num_node == 100) {
			// max number of booklist.
			return false;
		}
		
		if(hm.containsKey(bn.getTitle())==true) {
			// exist bookname -> fail
			return false;
		}
		else {
			// add to all collection
			al.add(bn);
			ll.add(bn);
			hs.add(bn);
			ts.add(bn);
			hm.put(bn.getTitle(), bn.getAuthor());
			tm.put(bn.getTitle(), bn.getAuthor());
			
			// plus 1 to number of nodes
			num_node += 1;
			return true;
		}
	}
	
	/*Print method*/
	public void printNode(String col, BufferedWriter flog) throws IOException{
		BookNode bn;
		String print;
		
		// sort al, ll
		Collections.sort(al);
		Collections.sort(ll);
		// tm, ts sorted by itself.
		// hm, hs don't sort
		
		// use at store book that name started by number
		TreeMap <String, String> tmp_tm = new TreeMap<String, String>();
		
		switch(col) // check collection name.
		{
		case "AL": // Print in ArrayList
			Iterator<BookNode> it_al = al.iterator(); // use iterator
			while(it_al.hasNext()) { // next is exist ?
				bn = it_al.next();
				if(bn.getTitle().charAt(0) <= '9' && bn.getTitle().charAt(0) >= '0')
				{
					tmp_tm.put(bn.getTitle(), bn.getAuthor());
					continue;
				}
				print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
				flog.write(print);
				flog.flush();
			}
			break;
		case "LL": // Print in LinkedList
			Iterator<BookNode> it_ll = ll.iterator();
			while(it_ll.hasNext()) {
				bn = it_ll.next();
				if(bn.getTitle().charAt(0) <= '9' && bn.getTitle().charAt(0) >= '0')
				{
					tmp_tm.put(bn.getTitle(), bn.getAuthor());
					continue;
				}
				print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
				flog.write(print);
				flog.flush();
			}
			break;
		case "HS": // Print in HashSet
			Iterator<BookNode> it_hs = hs.iterator();
			while(it_hs.hasNext()) {
				bn = it_hs.next();
				print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
				flog.write(print);
				flog.flush();
			}
			break;
		case "TS": // Print in TreeSet
			Iterator<BookNode> it_ts = ts.iterator();
			while(it_ts.hasNext()) {
				bn = it_ts.next();
				if(bn.getTitle().charAt(0) <= '9' && bn.getTitle().charAt(0) >= '0')
				{
					tmp_tm.put(bn.getTitle(), bn.getAuthor());
					continue;
				}
				print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
				flog.write(print);
				flog.flush();
			}
			break;
		case "HM": // Print in HashMap
			String key1;
			Set <String> st1 = hm.keySet(); // use keySet
			Iterator<String> it_hm = st1.iterator(); // iterator of keySet
			while(it_hm.hasNext()) { // next is exist ?
				key1 = it_hm.next();
				print = key1 + "/" +hm.get(key1)+ "\r\n"; // bring value by using keySet
				flog.write(print);
				flog.flush();
			}
			break;
		case "TM": // Print in TreeMap
			String key2;
			Set <String> st2 = tm.keySet();
			Iterator<String> it_tm = st2.iterator();
			while(it_tm.hasNext()) {
				key2 = it_tm.next();
				if(key2.charAt(0) <= '9' && key2.charAt(0) >= '0')
				{
					tmp_tm.put(key2, hm.get(key2));
					continue;
				}
				print = key2 + "/" +tm.get(key2)+ "\r\n";
				flog.write(print);
				flog.flush();
			}
			break;
		}
		
		// Print book that name started by number
		String key3;
		Set <String> st3 = tmp_tm.keySet();
		Iterator<String> it_tm2 = st3.iterator();
		while(it_tm2.hasNext()) {
			key3 = it_tm2.next();
			print = key3 + "/" +tm.get(key3)+ "\r\n";
			flog.write(print);
			flog.flush();
		}
	}
	
	/*Search method*/
	public String searchNode(String col, String book_name) {
		BookNode bn;
		String print;
		
		switch(col) // check collection name.
		{
		case "AL": // Search in ArrayList
			Iterator<BookNode> it_al = al.iterator();
			while(it_al.hasNext()) {
				bn = it_al.next();
				if( bn.getTitle().equals(book_name) == true ) { // find bookname!
					print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
					return print; // return result.
				}
			}
			return "error"; // can't find.
			
		case "LL": // Search in LinkedList
			Iterator<BookNode> it_ll = ll.iterator();
			while(it_ll.hasNext()) {
				bn = it_ll.next();
				if( bn.getTitle().equals(book_name) == true ) { // find bookname!
					print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
					return print;
				}
			}
			return "error";	// can't find
			
		case "HS": // Search in HashSet
			Iterator<BookNode> it_hs = hs.iterator();
			while(it_hs.hasNext()) {
				bn = it_hs.next();
				if( bn.getTitle().equals(book_name) == true ) { // find bookname!
					print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
					return print;
				}
			}
			return "error";	// can't find
			
		case "TS": // Search in TreeSet
			Iterator<BookNode> it_ts = ts.iterator();
			while(it_ts.hasNext()) {
				bn = it_ts.next();
				if( bn.getTitle().equals(book_name) == true ) { // find bookname!
					print = bn.getTitle()+"/"+bn.getAuthor()+"\r\n";
					return print;
				}
			}
			return "error";	// can't find
			
		case "HM": // Search in HashMap
			if( hm.get(book_name) != null ) { // exist bookname!
				print = book_name+"/"+hm.get(book_name)+"\r\n";
				return print;
			}
			return "error";	// can't find
		
		case "TM": // Search in TreeMap
			if( tm.get(book_name) != null ) { // exist bookname!
				print = book_name+"/"+tm.get(book_name)+"\r\n";
				return print;
			}
			return "error";	// can't find
		}
		return "error";	// can't find
	}
	
	/*Update method*/
	public String updateNode(String ori_book, String upt_book) {
		BookNode bn;
		String print = null;
		
		// Update in ArrayList
		Iterator<BookNode> it_al = al.iterator();
		while(it_al.hasNext()) {
			bn = it_al.next();
			if( bn.getTitle().equals(ori_book) == true ) {// if find bookname.
				bn.setTitle(upt_book);
				print = ori_book +" -> "+ upt_book +"\r\n";
			}
		}
		
		// if not exist book 
		if(print == null)
			return "error";
		
		// Update in LinkedList
		Iterator<BookNode> it_ll = ll.iterator();
		while(it_ll.hasNext()) {
			bn = it_ll.next();
			if( bn.getTitle().equals(ori_book) == true ) {// if find bookname.
				bn.setTitle(upt_book);
			}
		}
		
		// Update in HashSet
		Iterator<BookNode> it_hs = hs.iterator();
		while(it_hs.hasNext()) {
			bn = it_hs.next();
			if( bn.getTitle().equals(ori_book) == true ) {// if find bookname.
				bn.setTitle(upt_book);
			}
		}
		
		// Update in TreeSet
		Iterator<BookNode> it_ts = ts.iterator();
		while(it_ts.hasNext()) {
			bn = it_ts.next();
			if( bn.getTitle().equals(ori_book) == true ) {// if find bookname.
				bn.setTitle(upt_book);
			}
		}
		
		// Update in HashMap
		if( hm.get(ori_book) != null ) {// if exist bookname.
			hm.put(upt_book, hm.get(ori_book)); // put update book name / author
			hm.remove(ori_book);
		}
		
		// Update in TreeMap
		if( tm.get(ori_book) != null ) {// if exist bookname.
			tm.put(upt_book, tm.get(ori_book));
			tm.remove(ori_book);
		}
		
		
		return print;
	}

}
