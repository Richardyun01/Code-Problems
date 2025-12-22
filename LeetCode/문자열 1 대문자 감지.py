class Solution(object):
    def detectCapitalUse(self, word):
        up = 0
        down = 0
        for i in range(0, len(word)):
            if 'A' <= word[i] <= 'Z':
                up += 1
            elif 'a' <= word[i] <= 'z':
                down += 1
        if up == len(word):
            return True
        elif down == len(word):
            return True
        elif ('A' <= word[0] <= 'Z') == True and down == len(word)-1:
            return True
        return False

        # if (word.isupper()) or (word.islower()) or (word[0].isupper() and word[1:].islower()):
        #     return True
        # else:
        #     return False