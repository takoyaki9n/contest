using System;

namespace A_HonestOrDishonest {
    class Program {
        static void Main(string[] args) {
            // スペース区切りの整数の入力
            string[] input = Console.ReadLine().Split(' ');
            string a = input[0];
            string b = input[1];
            string ans = (a == b)? "H": "D";
            Console.WriteLine(ans);
        }
    }
}
