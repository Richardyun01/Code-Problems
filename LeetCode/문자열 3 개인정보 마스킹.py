class Solution(object):
    def maskPII(self, s):
        check_email = False
        email_idx = 0
        masked_email = ""
        code_number = 0
        local_number = ""
        masked_number = ""
        for i in range(len(s)):
            if s[i] == '@':
                email_idx = i
                check_email = True
        if check_email == True:
            masked_email += lower(s[0]) + "*****"
            for i in range(email_idx-1, len(s)):
                masked_email += lower(s[i])
            # print(masked_email)
            return masked_email
        else:
            tmp_string = ""
            for i in range(0, len(s)):
                if '0' <= s[i] <= "9":
                    tmp_string += s[i]
            # print(tmp_string)
            code_number = len(tmp_string) - 10
            for i in range(len(tmp_string)-4, len(tmp_string)):
                local_number += tmp_string[i]
            # print(local_number)
            if code_number == 0:
                masked_number += "***-***-" + local_number
            elif code_number == 1:
                masked_number += "+*-***-***-" + local_number
            elif code_number == 2:
                masked_number += "+**-***-***-" + local_number
            elif code_number == 3:
                masked_number += "+***-***-***-" + local_number
            # print(masked_number)
            return masked_number
        