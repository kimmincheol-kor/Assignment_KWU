package book;

import java.util.*;

public class BookNode implements Comparable<BookNode>{
	private String title;	//Book name;
	private String author;	//Book author;
	
	public BookNode() {
		
	}
	
	public BookNode(String i_title, String i_author) {
		title = new String(i_title);
		author = new String(i_author);
	}
	
	@Override
	public int compareTo(BookNode bn) { // Override compareTo() sorted by bookname.
		if(this.getTitle().compareTo( bn.getTitle() ) < 0)
			return -1;
		else if(this.getTitle().compareTo( bn.getTitle() ) > 0)
			return 1;
		else
			return 0;
	}
	
	public void setTitle(String i_title) { // set Title
		title = new String(i_title);
	}
	public void setAuthor(String i_author) { // set Author
		author = new String(i_author);
	}
	public String getTitle() { // get Title
		return title;
	}
	public String getAuthor() { // get Author
		return author;
	}

}
