/*****************************
 * Encode and Decode TinyURL *
 *****************************/

class Solution {
public:
    int count = 0;
    unordered_map<string, string> hash;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string returnUrl = "http://tinyurl.com/";
        returnUrl = returnUrl + to_string(count);
        count += 1;
            
        hash[returnUrl] = longUrl;
        return returnUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));