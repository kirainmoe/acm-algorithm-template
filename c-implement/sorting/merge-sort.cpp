int a[MAXN], b[MAXN], c[MAXN];
int n, m, ans = 0;
void merge_sort(int x, int y)
{
	if (y - x > 1) {
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;
		merge_sort(x, m);
		merge_sort(m, y);
		while (p < m || q < y) {
			if (q >= y || (p < m && a[p] <= a[q]))
				b[i++] = a[p++];
			else {
				b[i++]= a[q++];
				ans += m - p;
			}
		}
		for (i = x; i < y; i++)
			a[i] = b[i];
	}
}
