class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        negative = False
        if numerator < 0:
            negative = not negative
        if denominator < 0:
            negative = not negative

        print(negative)

        N, D = abs(numerator), abs(denominator)

        whole, remainder = divmod(N, D)

        def neg(s):
            print("herr", negative)
            if negative:
                return f"-{s}"
            return s

        if remainder == 0:
            if whole > 0:
                return neg(str(whole))
            return "0"

        seen = {}
        ans = []

        while remainder > 0:
            remainder *= 10
            digit, remainder = divmod(remainder, D)

            if (digit, remainder) in seen:
                # seen[digit] is the last time we've seen this digit
                return neg(
                    f"{whole}."
                    + "".join(ans[: seen[(digit, remainder)]])
                    + "("
                    + "".join(ans[seen[(digit, remainder)] :])
                    + ")"
                )

            seen[(digit, remainder)] = len(ans)
            ans.append(str(digit))

        # remainder == 0, the fraction ends
        return neg(f"{whole}." + "".join(ans))
