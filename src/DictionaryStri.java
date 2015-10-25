
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author dude
 */
public class DictionaryStri {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            String[] str = br.readLine().split(" ");
            int D = Integer.parseInt(str[0]);
            int S = Integer.parseInt(str[1]);
            String[] strD = new String[D];
            for (int i = 0; i < D; i++) {
                strD[i] = br.readLine();
            }

            int[] Arrmain=new int[26];
						int [][] cntAlph=new int[D][26];
						for (int i = 0; i < D; i++) {
										char[] arrS = strD[i].toCharArray();
										for (int j = 0; j < arrS.length; j++) {
														int val = (int) (arrS[j] - 'a');
														cntAlph[i][val] = cntAlph[i][val] + 1;
														Arrmain[val]=max(Arrmain[val],cntAlph[i][val]);
										}
						}
            String[] strP = new String[S];
            for (int x = 0; x < S; x++) {
                strP[x] = br.readLine();
                int[] arrF = new int[26];
                char[] arr = strP[x].toCharArray();
                int val = 0;
                for (int i = 0; i < arr.length; i++) {
                    val = (int) (arr[i] - 'a');
                    arrF[val] = arrF[val] + 1;
                }

                boolean cont=true;
            /*      for (int i = 0; i < D; i++) {
                    int[] arrD = new int[26];
                    char[] arrS = strD[i].toCharArray();

                    for (int j = 0; j < arrS.length; j++) {
                        val = (int) (arrS[j] - 'a');
                        arrD[val] = arrD[val] + 1;
                        Arrmain[val]=max(Arrmain[val],arrD[val]);
                    }
										}
                */    
                  for (int i = 0; i < D; i++) {
                    char[] arrS = strD[i].toCharArray();
                    for (int j = 0; j < arrS.length; j++) {
                        val=(int)(arrS[j]-'a');
                        if(arrF[val]>=cntAlph[i][val])
                            continue;
                        else{
                            cont=false;
                            break;
                        }
                    }
                    if(cont==false)
                        break;
										}
                if(cont==true)
                {
                    System.out.printf("Yes");
                    int cnt=0;
                    boolean chk=true;
                    for(int k=0;k<26;k++)
                    {
                        if(arrF[k]==Arrmain[k])
                            continue;
                        else{ 
                            chk=false;
                            break;
                        }
                    }
                    if(chk==true)
                        System.out.println(" Yes");
                    else
                        System.out.println(" No");
                }
                else
                {
                    System.out.printf("No ");
                    int cnt=0;
                     for(int k=0;k<26;k++)
                    {
                        if(arrF[k]==Arrmain[k])
                            continue;
                        else{ 
                            if(Arrmain[k]>arrF[k])
                            cnt=cnt+ (Arrmain[k]-arrF[k]);
                        }
                    }
                     System.out.println(cnt);
                }
								}
                
            }

        }
    
    private static int max(int a,int b)
    {
        return (a > b ? a: b);
    }

}

