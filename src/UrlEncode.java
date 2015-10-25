/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.nio.charset.Charset;
import static sun.security.krb5.Confounder.bytes;

/**
 *
 * @author dude
 */
public class UrlEncode{

    /**
     * @param args the command line arguments
     */
    static final String SS ="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static final int MAXRADIX = SS.length();
    private static Object Radixes;
    
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        //Charset.forName("UTF-8").encode(str);
        byte[] arr = str.getBytes("UTF-8");

      /*  for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }*/

        int N = Integer.parseInt(br.readLine());

        while (N-- > 0) {
            String target = br.readLine();
            byte[] arr1 = target.getBytes("UTF-8");
            

            int lb = arr.length;
            int lt = arr1.length;
                            byte[] arrNB = new byte[lt];

            if (lb > lt) {
                for(int i=0;i<lt;i++)
                {
                    arrNB[i]=arr[i];
                }
            } else {
                int i=0;
//                byte[] arrNB = new byte[lt];
                for (i = 0; i < lb; i++) {
                    arrNB[i] = arr[i];
                
                }
            }
                int j = 0;
                int i=lb;
                //int i = 0;
               // System.out.println("lb : "+lb+"lt: "+lt);
                //System.out.println("size of arrNB "+arrNB.length);
                for (i=lb; i < lt; i++) {
                   // System.out.println("i : "+i+" j "+j);
                            
                    arrNB[i] = arr[j%lb];
                    j++;
                }
                byte[] arrXor=new byte[lt];
                for(i=0;i<lt;i++)
                    arrXor[i]=(byte) ((arr1[i])^(arrNB[i]));
                
                 /*for (i = 0; i < lt; i++) {
                    System.out.printf("%d", arrXor[i]);
                }*/
                 ///System.out.println();
                  // System.out.println("lt : "+lt);
                 byte[] arrLastEight=new  byte[8];
//                 Array.Copy();
                
                 for(i=7;i>=0;i--)
                     arrLastEight[i]=arrXor[arrXor.length-(8-i)];
               
                /* for (i = 0; i < 8; i++) {
                    System.out.printf("%d", arrLastEight[i]);
                } */   
                 long l=java.nio.ByteBuffer.wrap(arrLastEight).getLong();
                 //System.out.println("L "+l);
                 StringBuilder sb=new StringBuilder(str);
                 String tmp=encode(l);
                // System.out.println("tmp "+tmp);
                                  sb.append("/");
                 sb.append(tmp);
                 System.out.println(sb.toString());
        }
}
    
    public static String encode(long number) {
		if(number < 0) {
			throw new IllegalArgumentException("Number cannot be negative");
		}
		
		StringBuilder builder = new StringBuilder(20);
                return encode(number,62); 
		//return builder.toString();
	}
	
         public static String encode(long value,int radix){
                if(radix > MAXRADIX){
                        throw new IllegalArgumentException("The parameter 'radix' cannot greater than [" + MAXRADIX +"]");
                }
                
                boolean revert = false;
                if(value < 0){
                        value = Math.abs(value);
                        revert = true;
                }
                
                String result = value==0?"0":"";
                while(value > 0){
                        int v = (int)(value % radix);
                        value = value / radix;
                        result = revert?(SS.charAt(radix - v -1)) + result:(SS.charAt(v)) + result;
                }
                
                return revert?SS.charAt(radix-1)+result:result;
        }
    
   

}

