using System;
using System.Collections;

namespace D_NoNeed {
    class Program {
        int N, K;
        int[] A;
        bool[,] DP;
        public Program(int K, int[] A) {
            this.N = A.Length;
            this.K = K;
            this.A = A;
            Array.Sort(A);
            this.DP = new bool[N + 1, K];
        }

        public bool NoNeed(int x) {
            // Console.WriteLine("A[{0}] = {1}", x, A[x]);

            for (int i = 0; i < N; i++) 
                for (int j = 0; j < K; j++) DP[i, j] = false;
            DP[0, 0] = true;

            for (int i = 0; i < N; i++) {
                int a = A[i];
                for (int j = 0; j < K; j++) {
                    DP[i + 1, j] = DP[i, j];
                    if (i != x && j - a >= 0) DP[i + 1, j] |= DP[i, j - a];
                }
            }

            // for (int i = 0; i <= N; i++) {
            //     for (int j = 0; j < K; j++) {
            //         Console.Write(DP[i, j]? "o": "x");
            //     }
            //     Console.WriteLine();
            // }
            // Console.WriteLine();
            
            for (int j = Math.Max(0, K - A[x]); j < K; j++) {
                if (DP[N, j]) return false;
            }
            return true;
        }
        static void Main(string[] args) {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int K = int.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            var A = new int[N];
            for (int i = 0; i < A.Length; i++) 
                A[i] = int.Parse(input[i]);
            var solve = new Program(K, A);
            int xl = -1, xr = N;
            while (xr - xl > 1) {
                // Console.WriteLine("[{0}, {1}]", xl, xr);
                int xm = (xl + xr) / 2;
                if(solve.NoNeed(xm)) {
                    xl = xm;
                } else {
                    xr = xm;
                }
            }
            Console.WriteLine(xr);
        }
    }
}
