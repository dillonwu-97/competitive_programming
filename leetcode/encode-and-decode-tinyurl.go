import (
    "crypto/md5"
    "fmt"
)
type Codec struct {
    d map[string]string
    }
func Constructor() Codec {
    return Codec{
        d:map[string]string{},
    }
}
// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
    data := []byte(longUrl)
    mdval := md5.Sum(data)
    mdstr := string(mdval[:])
    var ret string
    for i:=4; i < len(mdstr); i++ {
        if _, ok := this.d[ mdstr[:i] ]; !ok {
            ret = mdstr[:i]
            this.d[ mdstr[:i] ] = longUrl
            break
        }
    }
    return ret
}
// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
    return this.d [shortUrl]
}
/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */