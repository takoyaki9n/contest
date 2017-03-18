using System;
using System.Collections.Generic;

namespace C_GoHome {
    class Program {
        static void Main(string[] args) {
            int X = int.Parse(Console.ReadLine());
            int i = 0, x = 0;
            while(true) {
                x += i;
                if (x >= X) break;
                i++;
            }
            Console.WriteLine(i);
        }
    }
}
