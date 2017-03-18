using System;

namespace A_HonestOrDishonest {
    class Program {
        static void Main(string[] args) {
            // スペース区切りの整数の入力
            string[] input = Console.ReadLine().Split(' ');
            int W = int.Parse(input[0]);
            int a = int.Parse(input[1]);
            int b = int.Parse(input[2]);
            int ans = Math.Max(Math.Abs(a - b) - W, 0);
            Console.WriteLine(ans);
        }
    }
}
