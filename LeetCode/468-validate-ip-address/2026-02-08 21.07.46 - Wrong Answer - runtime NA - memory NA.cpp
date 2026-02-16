class Solution {
public:
    string validIPAddress(string queryIP) {
        int n = queryIP.size();
        bool hasDot = false;
        bool hasColon = false;
        for (char c : queryIP) {
            if (c == '.') hasDot = true;
            if (c == ':') hasColon = true;
        }
        if (hasDot && hasColon) return "Neither";
        if (hasDot) {
            int i = 0;
            int segments = 0;
            while (i < n) {
                if (segments == 4) return "Neither";
                int j = i;
                while (i < n && queryIP[i] != '.') i++;
                int len = i - j;
                if (len == 0 || len > 3) return "Neither";
                if (len > 1 && queryIP[j] == '0') return "Neither";
                int num = 0;
                for (int k = j; k < i; k++) {
                    char c = queryIP[k];
                    if (c < '0' || c > '9') return "Neither";
                    num = num * 10 + (c - '0');
                }
                if (num > 255) return "Neither";
                segments++;
                if (i < n && queryIP[i] == '.') i++;
            }
            return segments == 4 ? "IPv4" : "Neither";
        }
        if (hasColon) {
            int i = 0;
            int segments = 0;
            while (i < n) {
                if (segments == 8) return "Neither";
                int j = i;
                while (i < n && queryIP[i] != ':') i++;
                int len = i - j;
                if (len == 0 || len > 4) return "Neither";
                for (int k = j; k < i; k++) {
                    char c = queryIP[k];
                    bool ok = (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
                    if (!ok) return "Neither";
                }
                segments++;
                if (i < n && queryIP[i] == ':') i++;
            }
            return segments == 8 ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};
