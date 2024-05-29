using System;
using System.Net;
using Pmp;
using System.Threading;
using System.IO;

namespace PmpGettingStartedCs
{
    internal class Levitation
    {
        public ITopController TopController { set; get; }
        public string FilePath { set; get; }
        public string ConfigPath { set; get; }
        public string CouplerPath { set; get; }
        public string BusPath { set; get; }
        public string Name { set; get; }
        public string Address { set; get; }

        public IAxisControlGroup VerticalAxis { set; get; }

        public ICommandQueue VerticalQueue { set; get; }

        public IAxisControlGroup LateralAxis { set; get; }

        public ICommandQueue LateralQueue { set; get; }
        public IProcessingBlock LateralController { set; get; }

        public IProcessingBlock VerticalController { set; get; }
        public ISignal LaneSwitchSignal { set; get; }

        public ISignal VerticalMode { set; get; }

        public ISignal LateralMode { set; get; }
        public void SetNameAdress()
        {
            this.Address = "255.255.255.255";
            this.Name = "Arcas 5EG-0";
        }

        public void ExecuteCommand(string command)
        {
            switch (command)
                {
                case "enable_axis":
                    try
                    {
                        EnableAndMove.EnableAxis(this);

                    }
                    catch (Exception) 
                    {
                        Console.WriteLine("axis_error\n");
                    }
                    break;

                case "disable_axis":
                    try
                    {
                        EnableAndMove.DisableAxis(this);

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("axis_error\n");
                    }
                    break;

                case "init":
                    try
                    {
                        this.Initialize();
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("init_error\n");
                    }
                    break;

                case "reboot":
                    try
                    {
                        ControllerDiscoveryAndInit.Reboot(this);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("reboot_error\n");
                    }
                    break;

                case "launch":
                    try
                    {
                        this.SetVerticalMode(0);
                        Console.Write("launching\n");
                        Thread.Sleep(7000);
                        this.SetLateralMode(1);
                        Console.Write("launch_complete\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("mode_error\n");
                    }
                    break;

                case "vert0":
                    try
                    {
                        this.SetVerticalMode(-1);
                        Console.Write("mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("mode_error\n");
                    }
                    break;

                case "lat0":
                    try
                    {
                        this.SetLateralMode(-1);
                        Console.Write("mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("mode_error\n");
                    }
                    break;

                case "land":
                    try
                    {
                        this.SetLateralMode(2);
                        this.SetVerticalMode(3);
                        Console.Write("landing\n");
                        Thread.Sleep(10000);
                        this.SetVerticalMode(2);

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("mode_error\n");
                    }
                    break;

                case "ls0":
                    try
                    {
                        this.SetLaneSwitch(0);
                        Console.Write("ls_Set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ls_error\n");
                    }
                    break;
                    
                case "ls1":
                    try
                    {
                        this.SetLaneSwitch(1);
                        Console.Write("ls_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ls_error\n");
                    }
                    break;

                case "ls2":
                    try
                    {
                        int time = DateTime.Now.Millisecond;
                        this.SetLaneSwitch(2);
                        Console.Write("ls_set\n");

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ls_error\n");
                    }
                    break;

                default:
                    Console.WriteLine("invalid\n");
                    break;

            }
        }
        public void SetPaths()
        {
            this.FilePath = Directory.GetCurrentDirectory();
            this.FilePath = Directory.GetParent(FilePath).FullName;
            /*            this.FilePath = this.FilePath + "\\Levi";*/
            this.ConfigPath = this.FilePath + "\\levitation_config_file.xml";
            this.CouplerPath = this.FilePath + "\\00000002_044c2c52_0012.xml";
            this.BusPath = this.FilePath + "\\00000002_0c203052_0014.xml";
        }

        public void SetSignals()
        {
            this.LateralController = this.TopController.ProcessingBlocks["LateralController"];
            this.VerticalController = this.TopController.ProcessingBlocks["Airgap_controllers"];
            this.LaneSwitchSignal = this.LateralController.Signals["LS_mode"];
            this.LateralMode = this.LateralController.Signals["LateralOperatingMode"];
            this.VerticalMode = this.VerticalController.Signals["OperatingMode"];
            this.VerticalAxis = this.TopController.AxisControlGroups["AxisControlGroup"];
            this.VerticalQueue = this.VerticalAxis.CommandQueue;
            this.LateralAxis = this.TopController.AxisControlGroups["AxisControl_Lateral"];
            this.LateralQueue = this.LateralAxis.CommandQueue;
        }
        public bool SetLaneSwitch(double value)
    {
        Acquisition.ChangeSignalFromSignal(this.LaneSwitchSignal, value);
        return true;
    }

        public bool SetVerticalMode(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.VerticalMode, value);
            return true;
        }

        public bool SetLateralMode(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.LateralMode, value);
            return true;
        }

        public void Initialize()
        {
            this.SetNameAdress();
            this.SetPaths();
            this.TopController = ControllerDiscoveryAndInit.DiscoveryAndInit(this);
            this.SetSignals();
        }
public static int Main()
        {
            Levitation arcas = new Levitation();
           

  try
  {
                arcas.Initialize();

                Console.WriteLine("SampleCount: {0}", arcas.TopController.Signals["SampleCount"].ValueUint32);
                

                /*    var axisControl = EnableAndMove.EnableAndMoveAxis(arcas.topController);*/

                /*    Acquisition.RunAcquisition(arcas.topController);*/
                while (true)
                {

                    string command = (InputsOutputs.ReadConsole());
                    arcas.ExecuteCommand(command);
                }
            }
  catch (PmpException ex)
  {
    Console.WriteLine("Error encountered: {0}", ex.Message);
                Thread.Sleep(10000);

    return 1;
  }

  if (arcas.TopController != null)
  {
    arcas.TopController.Dispose();
  }

  return 0;
}
}
}