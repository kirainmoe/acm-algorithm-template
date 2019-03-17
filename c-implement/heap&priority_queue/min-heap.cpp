struct Heap {
    long long val[MAXN];
    int cnt;
    void init()
    {
        memset(val, 0, sizeof val);
        cnt = 0;
    }

    void insert(int x)
    {
        val[++cnt] = x;
        int tmp = cnt;
        while (tmp != 0) {
            int par = tmp / 2;
            if (val[par] > x) {
                std::swap(val[par], val[tmp]);
            } else
                break;
            tmp = par;
        }
    }

    int top()
    {
        return val[1];
    }

    void pop()
    {
        if (cnt == 0)    // empty
            return;
        int rt = 1;
        val[rt] = val[cnt];
        while (2 * rt < cnt)
        {
            int lc = rt << 1, rc = (rt << 1) + 1;
            if (rc >= cnt || val[lc] < val[rc]) {
                if (val[rt] > val[lc]) {
                    std::swap(val[rt], val[lc]);
                    rt = lc;
                } else
                    break;
            } else {
                if (val[rt] > val[rc]) {
                    std::swap(val[rt], val[rc]);
                    rt = rc;
                } else {
                    break;
                }
            }
        }
        cnt--;
    }

    bool empty()
    {
        return cnt == 0;
    }
};
