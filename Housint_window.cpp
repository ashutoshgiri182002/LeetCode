class Solution {
public:
    string minWindow(string s, string t) {
        
        string p = t;
        //Array as a freq map
   int FP[256] = {0};
   int FS[256] = {0};

   for(int i=0;i<p.length();i++){
     FP[p[i]]++;
   }

   //sliding window algorithm
   int cnt = 0;
   int start = 0;  //left contraction
   int start_idx = -1;  //start_idx for best window
   int min_so_far = INT_MAX;
   int window_size;
   for(int i = 0;i<s.length();i++){
      //expand the window by including current character
      char ch = s[i];
      FS[s[i]]++;

      //count how many character have been matched till now (string and pattern)
      if(FP[ch]!=0 and FS[ch] <= FP[ch]){
        cnt +=1;
      }

      //another thing
      //if all character of the pattern are found in the current window then you
      //can start contracting
      if(cnt==p.length()){
        //start contracting from the left to remove unwanted character

        while(FP[s[start]]==0 or FS[s[start]]>FP[s[start]]){
          FS[s[start]]--;
          start++;
        }
        //note the window size
        int window_size = i - start + 1;
        if(window_size < min_so_far){
          min_so_far = window_size;
          start_idx = start;
        }
      }
   }

   if(start_idx == -1){
     return "";
   }
   return s.substr(start_idx,min_so_far);
        
    }
};
