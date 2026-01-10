class Solution:
    def magicalString(self, n: int) -> int:
        magic = ""
        for i in range(1, n+1):
            if i % 2 == 0:
                magic += "2"
                if magic[i-1] == "1":
                    continue
                elif magic[i-1] == "2":
                    magic += "2"
            elif i % 2 == 1:
                magic += "1"
                if magic[i-1] == "1":
                    continue
                elif magic[i-1] == "2":
                    magic += "1"
        sum = 0
        for i in magic[:n]:
            print(i)
            if i == '1':
                sum += 1
        print(magic[:6])
        return sum
