/*****************************
 * Encode and Decode TinyURL *
 *****************************/

public class Codec {
    int count = 0;
    Dictionary<string, string> hash = new Dictionary<string,string>();
    
    // Encodes a URL to a shortened URL
    public string encode(string longUrl) {
        string returnUrl = "http://tinyurl.com/";
        returnUrl = returnUrl + count.ToString();
        count += 1;
            
        if(!hash.TryGetValue(returnUrl, out string _longUrl))
            hash.Add(returnUrl, longUrl);
        
        return returnUrl;
    }

    // Decodes a shortened URL to its original URL.
    public string decode(string shortUrl) {
        return hash[shortUrl];
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));