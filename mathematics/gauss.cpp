#include <cstdio>
#include <cmath> 
#include <algorithm>

const int MAXN = 205;
const double eps = 1e-8;        // 浮点误差

int n;
double del;
double a[MAXN][MAXN];

bool gauss() {
    // 对每个式子进行枚举 
    for (int i = 0; i < n; i++) {
        int k = i;
        // 从 i 的下一个等式开始枚举 
        for (int j = i + 1; j < n; j++) {
            // 比较第 k 个式子和第 j 个式子中未知数 i 系数的大小, fabs() 表示对浮点数取绝对值 
            if (fabs(a[j][i]) > fabs(a[k][i])) {
                k = j;      // 找到第 i 个未知数系数最大的 
            }
        }

        del = a[k][i];

        // 如果有一个未知数在所有式子中的系数都为 0（绝对值最大值小于浮点误差），则无解 
        if (fabs(del) < eps) {
            return false;
        }

        // 对于当前式子，与第 k 个式子交换所有项的系数，即当前式子实为未知数 i 系数最大的第 k 个式子 
        for (int j = i; j <= n; j++) {
            std::swap(a[i][j], a[k][j]);
        }

        // 然后对当前式子的所有项（包括值）消去第 k 个式子中第 i 个未知数的系数 
        for (int j = i; j <= n; j++) {
            a[i][j] /= del;
        }

        // 处理其它的式子，对各项加上/减去相同系数 
        for (k = 0; k < n; k++) {
            // 只对非当前式子操作 
            if (k != i) {
                del = a[k][i];
                for (int j = i; j <= n; j++) {
                    a[k][j] -= a[i][j] * del;
                }
            }
        }
    }
    return true;
}

int main() {
    // 未知数的数目 
    scanf("%d", &n);

    // n 个未知数，至少需要有 n 个等式才能求解，否则无解 
    for (int i = 0; i < n; i++) { 
        // 注意第二个循环体的条件是 j <= n，不要忘记了除了系数外还要输入一个多项式的值 
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    // a[i][j] 表示在第 i 个等式中第 j 个未知数的系数 

    // 高斯消元求解，如果该方程组有解，返回 true 
    bool flag = gauss(); 

    if (!flag) {
        // 无解
        printf("No Solution");
    } else {
        for (int i = 0; i < n; i++) {
            // 输出第 i 个式子的值，即为第 i 个未知数的答案
            printf("%.2lf\n", a[i][n]);
        }
    }

    return 0;
}
