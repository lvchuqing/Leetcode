/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
public class Solution {
        public static int trap(int[] A) {
	        if(A.length<2) return 0;

	        ArrayList<Integer> tops = new ArrayList<Integer>();
	        //int start == 0;
	        int prev = A[1];
	        int result = 0;
	        HashMap<Integer, Integer> tempRes = new HashMap<Integer, Integer>();
	        boolean decsend;
	        if(A[1]>A[0]) decsend = false;
	        else{
	        	decsend = true;
	        	tops.add(0);
	        	tempRes.put(0, 0);
	        }

	        for(int i=2; i<=A.length; ++i){
                int elem = 0;
                if(i<A.length) elem = A[i];
	            if(!decsend && elem<prev){
	                //start == 1;
	                tops.add(new Integer(i-1));
	                result = calculateWater(A, tops, tempRes);
	                tempRes.put(new Integer(i-1), new Integer(result));
	                decsend = true;
	            }
	            if(decsend && elem>prev){
	            	decsend = false;
	            }
	            
	            prev = elem;
	        }
	        
	        return result;
	    }
	    
	    public static int calculateWater(int[] A, ArrayList<Integer> tops, HashMap<Integer, Integer> tempRes){
	        if(tops.size()<2) return 0;
	        int curTop = tops.get(tops.size()-1);
	        int anotherTop = tops.get(tops.size()-2);
	        for(int i = tops.size()-2; i>=0; --i){
                
	            if(A[tops.get(i)]>=A[curTop]){
	                anotherTop = tops.get(i);
	                break;
	            }
                if(A[anotherTop]<A[tops.get(i)]){
                    anotherTop = tops.get(i);
                }
	        }
	        int minTop = A[anotherTop]<A[curTop]?A[anotherTop]:A[curTop];
	        int res = 0;
	        for(int j=anotherTop+1; j<curTop; ++j){
                 int temp = minTop-A[j];
	             if(temp>0)res+=temp;
	        }
	            
	        return res+tempRes.get(new Integer(anotherTop));

	    }
	
}
