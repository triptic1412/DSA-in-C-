/*
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. 
Every revision contains at least one character. 
Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. 
For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. 
Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. 
If a version number does not specify a revision at an index, then treat the revision as 0. 
For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

*/
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.length(), m = v2.length();
        int i = 0, j = 0;
        while(i<n or j<m){
            string a = "";
            while(i<n and v1[i]!='.'){
                if(v1[i]=='0' and a.empty())
                    i++;
                else
                    a += v1[i++];
            }
            if(a.empty())
                a = "0";
            
            string b = "";
            while(j<m and v2[j]!='.'){
                if(v2[j]=='0' and b.empty())
                    j++;
                else
                    b += v2[j++];
            }
            
            if(b.empty())
                b = "0";
            
            int al = a.length(), bl = b.length();
            if(al<bl)
                return -1;
            else if(bl<al)
                return 1;
            else if(al==bl){
                if(a<b)
                    return -1;
                else if(b<a)
                    return 1;
            }
            i++;j++;
        }
        return 0;
    }
};
