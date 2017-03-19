using System;

namespace D_NoNeed {
    class Program {
        static void Main(string[] args) {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int K = int.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            var A = new int[N];
            for (int i = 0; i < A.Length; i++) 
                A[i] = int.Parse(input[i]);
        //    Array.Sort(A);

            bool[,] DP = new bool[N + 1, K];
            for (int i = 0; i <= N; i++)
                for (int j = 0; j < K; j++)
                    DP[i, j] = false;
            DP[0, 0] = true;
            int ans = 0;
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    int a = A[i];
                    if (i == k) {
                        for (int j = 0; j < K; j++) DP[i + 1, j] = DP[i, j];
                    } else {
                        for (int j = 0; j < K; j++) { 
                            DP[i + 1, j] = DP[i, j];
                            if (j - a >= 0) DP[i + 1, j] |= DP[i, j - a];
                        }
                    }
                    // for (int j = 0; j < K; j++) Console.Write(DP[i, j]? "o ": "x ");
                    // Console.WriteLine();
                }
                // for (int j = 0; j < K; j++) Console.Write(DP[N, j]? "o ": "x ");
                // Console.WriteLine();
                bool flag = false;
                for (int j = Math.Max(0,  K - A[k]); j < K; j++) {
                    flag |= DP[N, j];
                }
                if (!flag) ans++;
                // Console.WriteLine();
            }
            Console.WriteLine(ans);
        }
    }
}
