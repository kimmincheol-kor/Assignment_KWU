package book;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class main {
	
	public static void main(String [] args) throws IOException{
		Manager manager = new Manager(); // make instance of manager
		manager.run("command.txt"); // run Manager.
	}
}
