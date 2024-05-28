using System.Runtime.Remoting.Messaging;
using System;
using Pmp;
using System.IO;
using System.Diagnostics;
using static Pmp.Unmanaged.Abi;
using static System.Net.Mime.MediaTypeNames;

namespace PmpGettingStartedCs
{
    public class InputsOutputs
    {
        Process p { set; get; }
        public StreamWriter sw { set; get; }
        public StreamReader sr { set; get; }

        public void Initialize()
        {
            ProcessStartInfo psi = new ProcessStartInfo("cmd.exe")
            {
                RedirectStandardError = false,
                RedirectStandardInput = false,
                RedirectStandardOutput = false,
                UseShellExecute = true,
                CreateNoWindow = false,
                WindowStyle = ProcessWindowStyle.Normal,
                Arguments = "Hallo"
        };

            this.p = Process.Start(psi);
/*            this.sw = p.StandardInput;
            this.sr = p.StandardOutput;*/
        }
        public static string ReadInputs()
        {
            return System.Console.ReadKey().KeyChar.ToString();
        }
        public static string ReadConsole()
        {
            return System.Console.ReadLine().ToString();
        }

        public static int ReadConsoleInt()
        {
            return Int32.Parse(System.Console.ReadLine().ToString());
        }
        public static void WriteConsole(string value)
        {
            System.Console.WriteLine(value);
        }

        
        public string ReadConsoleOther()
        {
            return sr.ReadLine().ToString();
        }
        public void WriteConsoleOther(string value)
        {
            sw.WriteLine(value);
        }
    }
}