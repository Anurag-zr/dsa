#include<bits/stdc++.h>
using namespace std;


// not optimal getting TLE
// bool isAnagram(unordered_map<char,int> pcount_mp,unordered_map<char,int> scount_mp){
//    for(auto it: pcount_mp){
//     if(pcount_mp[it.first]!=scount_mp[it.first]) return false;
//    }

//    return true;
// }

// int countOcurrenceofAnagram(string s,string p){

//     unordered_map<char, int> scount_mp;
//     unordered_map<char, int> pcount_mp;
//     int n = s.size();
//     int k = p.size();
//     int count = 0;

//     for(auto it:p){
//         pcount_mp[it] += 1;
//     }

//     int i = 0;
//     for (int j = 0; j < n;j++){
//         scount_mp[s[j]] += 1;

//         if(j-i+1 == k){
//            if(isAnagram(pcount_mp,scount_mp)){
//                count++;
//                cout << s.substr(i, k) << endl;
//            }

//            scount_mp[s[i]] -= 1;
//            i++;
//         }

      
//     }

//     return count;
// }



vector<string> findAnagram(const std::string& text,
                            const std::string& word)
    {
        int text_length = text.length();
        int word_length = word.length();
        if (text_length < 0 || word_length < 0
            || text_length < word_length)
            return {};
 
        constexpr int CHARACTERS = 256;
        vector<string> ans;
        int index = 0;
        std::array<char, CHARACTERS> wordArr;
        wordArr.fill(0);   //filling up null character in array
        std::array<char, CHARACTERS> textArr;
        textArr.fill(0);



        // till window size
        for (; index < word_length; index++) {
            wordArr[CHARACTERS - word[index]]++;
            textArr[CHARACTERS - text[index]]++;
        }
        if (wordArr == textArr)
            ans.push_back(text.substr(0, word.length()));
        // next window
        for (; index < text_length; index++) {
            textArr[CHARACTERS - text[index]]++;
            textArr[CHARACTERS
                    - text[index - word_length]]--;
 
            if (wordArr == textArr)
                ans.push_back(text.substr(index-word_length+1,word_length));
        }
        return ans;
    }

    
    //gfg code

    // int countOcurrenceofAnagram(string s,string p){
    //  int count = 0;
    //  int n = s.size();
    //  int k = p.size(); //window size
    //  vector<int> wordArr(256,0);
    //  vector<int> txtArr(256,0);
    

    //  int index = 0; 
    //          // till window size
    //     for (; index < p.size(); index++) {
    //         wordArr[p[index]]++;
    //         cout << wordArr[p[index]] << endl;
    //         txtArr[s[index]]++;
    //     }
    //     if (wordArr == txtArr)
    //         count++;
    //     // next window
    //     for (; index < s.size(); index++) {
    //         txtArr[s[index]]++;
    //         txtArr[s[index - k]]--;
 
    //         if (wordArr == txtArr)
    //             count++;
    //     }



    //  return count;
    // }

    int countOcurrenceofAnagram(string s,string p){
     int count = 0;
     int n = s.size();
     int k = p.size(); //window size
     vector<int> wordArr(256,0);
     vector<int> txtArr(256,0);

        int i=0;
        wordArr[p[0]]++;
        for (int j = 0; j < n;j++){
            txtArr[s[j]]++;

            if(j-i+1<k){
             wordArr[p[j+1]]++; 
            }

            if(j-i+1 == k){
                // for (int q = 0;q<wordArr.size();q++){
                //     cout << wordArr[q] << "   " << txtArr[q] << endl;
                // }
                    if (wordArr == txtArr)
                    {
                        count++;
                    }

                txtArr[s[j - k+1]]--;
                i++;
            }
        }

        return count;
    }



int main(){

    string txt = "forxxorfxdofr";
    string ptr = "for";

    // vector<string> ans = findAnagram(txt, ptr);

    // for(auto it:ans){
    //     cout << it << endl;
    // }

    cout << countOcurrenceofAnagram(txt, ptr) << endl;
}