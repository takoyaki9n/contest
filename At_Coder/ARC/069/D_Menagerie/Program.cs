using System;

namespace D_Menagerie {
    class Program {
        static string Solve(string input) {
            var N = input.Length;
            var prefs = new string[]{"SS", "SW", "WS", "WW"};
            foreach (var pref in prefs) {
                var ans = pref;
                for (int i = 2; i < N; i++) {
                    ans += Guess(ans[i - 1], ans[i - 2], input[i - 1]);
                }
                var valid = ans[0] == Guess(ans[N - 1], ans[N - 2], input[N - 1]) && ans[1] == Guess(ans[0], ans[N - 1], input[0]);
                if (valid) return ans;
            }
            return "-1";
        }
        static char Guess(char x, char y, char a) {
            var flag = (y == 'S') ^ (a == 'o') ^ (x == 'S');
            return flag? 'S': 'W';
        }
        static void Main(string[] args) {
            var N = int.Parse(Console.ReadLine());
            var str = Console.ReadLine();
            Console.WriteLine(Solve(str));
        }
    }
}
