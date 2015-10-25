/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rpattern;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author dude
 */
public class RPattern {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        // TODO code application logic here
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        while(T-- > 0)
        {
            String str=br.readLine();
//            System.out.println(len);
            String repeated=str.replaceAll("(.+?)\\2+", "$1");
            //System.out.println(repeated);
           // repeated=repeated.replaceAll("(.+?)\\1+", "$1");
            long l=repeated.length();
            
            //String patt=FindPattern(str);
            //System.out.println(patt.length());
            System.out.println(l);
            
        }

    }
    
  /*  
    public static String FindPattern(String s)
{
    for (long length = 1; length <= (s.length())/ 2; length++)
    {
        String pattern = s.substring(0, (int) length);
        char[] arr=pattern.toCharArray();
        char [] arrS=s.toCharArray();
        if(MatchesPattern(arrS,arr))
        {a
            return pattern;
        }
    }
    return s;
}

public static boolean MatchesPattern(char[] s, char[] Pattern)
{
    for (int i = 0; i < s.length; i++)
    {
        //if(!s[i].Equals(pattern[i%pattern.Length]))
            if(Pattern[i%(Pattern.length)]!= s[i])
        {
            return false;
        }
    }
    return true;
}
    */
}
