class Solution(object):
    def prefixCount(self, words, pref):
        """
        :type words: List[str]
        :type pref: str
        :rtype: int
        """
        size = len(pref)
        ret = 0
        for word in words:
            if len(word)<size:
                continue
            else :
                if word[:size] == pref:
                    ret=ret+1
                else:
                    continue
        
        return ret