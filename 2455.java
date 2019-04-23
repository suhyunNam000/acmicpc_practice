import java.util.*;
import java.lang.*;
import java.io.*;
//지능형 기차
//https://www.acmicpc.net/problem/2455
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int income;  int outgo;
		int max_passenger = 0;
		int now_passenger = 0;
		
        Scanner scan = new Scanner(System.in);
        
        for(int i=0; i<4; i++) {
          
          outgo = scan.nextInt();
          now_passenger = now_passenger - outgo;
          if(max_passenger < now_passenger)	max_passenger = now_passenger;
          
          income = scan.nextInt();
          now_passenger = now_passenger + income;
          if(max_passenger < now_passenger)	max_passenger = now_passenger;
          
        }
        
        System.out.println( max_passenger );
	}
}