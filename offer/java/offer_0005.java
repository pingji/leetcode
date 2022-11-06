class Solution {
    public String replaceSpace(String s) {
        int oldLength = s.length();
        int spaceCount = 0;
        for (int i = 0; i < oldLength; i++)
        {
            if (s.charAt(i) == ' ')
            {
                spaceCount++;
            }
        }
        int newLength = oldLength + 2 * spaceCount;
        char[] array = new char[newLength];
        int i = oldLength - 1;
        int j = newLength - 1;
        while (i >= 0)
        {
            if(s.charAt(i) == ' ') {
                array[j] = '0';
                array[j-1] = '2';
                array[j-2] = '%';
                i--;
                j -= 3;
            } else {
                array[j] = s.charAt(i);
                i--;
                j--;
            }
        }
        return new String(array);
    }
}