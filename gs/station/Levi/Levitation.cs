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

        public IProcessingBlock LaserSensors { set; get; }
        public ISignal LaneSwitchSignal { set; get; }

        public ISignal VerticalMode { set; get; }

        public ISignal LateralMode { set; get; }

        public ISignal G_A { set; get; }
        public ISignal G_A2 { set; get; }
        public ISignal G_B { set; get; }
        public ISignal G_B2 { set; get; }
        public ISignal G_C { set; get; }
        public ISignal G_C2 { set; get; }
        public ISignal G_D { set; get; }
        public ISignal G_D2 { set; get; }

        public ISignal I_A1 { set; get; }
        public ISignal I_A2 { set; get; }
        public ISignal I_B1 { set; get; }
        public ISignal I_B2 { set; get; }
        public ISignal I_C1 { set; get; }
        public ISignal I_C2 { set; get; }
        public ISignal I_D1 { set; get; }
        public ISignal I_D2 { set; get; }
        public ISignal I_Front { set; get; }
        public ISignal I_Back { set; get; }
        public ISignal Offset_AB { set; get; }
        public ISignal Offset_CD { set; get; }
        public ISignal Motor_Enabled { set; get; }



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
                        Console.WriteLine("INFO:enabling_levi_HV\n");
                        EnableAndMove.EnableAxis(this);

                    }
                    catch (Exception) 
                    {
                        Console.WriteLine("ERROR:axis_error\n");
                    }
                    break;

                case "disable_axis":
                    try
                    {
                        Console.WriteLine("INFO:disabling_levi_HV\n");
                        EnableAndMove.DisableAxis(this);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:axis_error\n");
                    }
                    break;

                case "init":
                    try
                    {
                        Console.WriteLine("INFO:initializing\n");
                        this.Initialize();
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("WARNING:init_error\n");
                    }
                    break;

                case "reboot":
                    try
                    {
                        Console.WriteLine("INFO:rebooting\n");
                        ControllerDiscoveryAndInit.Reboot(this);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("WARNING:reboot_error\n");
                    }
                    break;

                case "launch":
                    try
                    {
                        this.SetVerticalMode(0);
                        Console.Write("INFO:launching\n");
                        Thread.Sleep(7000);
                        this.SetLateralMode(1);
                        Console.Write("INFO:launch_complete\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ERROR:mode_error\n");
                    }
                    break;

                case "vert0":
                    try
                    {
                        this.SetVerticalMode(-1);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "lat0":
                    try
                    {
                        this.SetLateralMode(-1);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "land":
                    try
                    {
                        this.SetLateralMode(2);
                        this.SetVerticalMode(3);
                        Console.Write("INFO:landing\n");
                        Thread.Sleep(10000);
                        this.SetVerticalMode(2);
                        Console.Write("INFO:landed\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "ls0":
                    try
                    {
                        this.SetLaneSwitch(0);
                        Console.Write("INFO:ls_Set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:ls_error\n");
                    }
                    break;
                    
                case "ls1":
                    try
                    {
                        this.SetLaneSwitch(1);
                        Console.Write("INFO:ls_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:ls_error\n");
                    }
                    break;

                case "ls2":
                    try
                    {
                        int time = DateTime.Now.Millisecond;
                        this.SetLaneSwitch(2);
                        Console.Write("INFO:ls_set\n");

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:ls_error\n");
                    }
                    break;

                default:
                    Console.WriteLine("WARNING:invalid\n");
                    break;

            }
        }
        public void SetPaths()
        {
            this.FilePath   = Directory.GetCurrentDirectory();
/*            this.FilePath = Directory.GetParent(FilePath).FullName;*/
            this.FilePath = this.FilePath + "\\Levi";
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
            this.LaserSensors = this.TopController.ProcessingBlocks["LaserSensors"];

            // Define the Cygni
            var CygnusA = this.TopController.Controllers["Cygnus A"];
            var CygnusB = this.TopController.Controllers["Cygnus B"];
            var CygnusC = this.TopController.Controllers["Cygnus C"];
            var CygnusD = this.TopController.Controllers["Cygnus D"];
            var CygnusE = this.TopController.Controllers["Cygnus E"];

            // Define the motor outputs
            var MotA1 = CygnusA.Actuators["Mot1"];
            var MotA2 = CygnusA.Actuators["Mot2"];
            var MotB1 = CygnusB.Actuators["Mot1"];
            var MotB2 = CygnusB.Actuators["Mot2"];
            var MotC1 = CygnusC.Actuators["Mot1"];
            var MotC2 = CygnusC.Actuators["Mot2"];
            var MotD1 = CygnusD.Actuators["Mot1"];
            var MotD2 = CygnusD.Actuators["Mot2"];
            var MotE1_Front = CygnusE.Actuators["Mot_E1_Front"];
            var MotE2_Back = CygnusE.Actuators["Mot_E2_Back"];

            /* VerticalAxiscontrol_Enabled = LaserSensors.Signals["VerticalAxiscontrol_Enabled"];
             VerticalAxiscontrol_Enabled = LaserSensors.Signals["LateralAxiscontrol_Enabled"];*/
            //Start_Levitating = FSM.Signals["Start_Levitating"];
            //Stop_Levitating = FSM.Signals["Stop_Levitating"];
            this.Motor_Enabled = VerticalController.Signals["PropulsionOn"];
            //At_Top = FSM.Signals["At_Top"];
            //Reset = FSM_Feedthrough.Signals["Reset"];
            this.G_A = LaserSensors.Signals["G_A"];
            this.G_B = LaserSensors.Signals["G_B"];
            this.G_C = LaserSensors.Signals["G_C"];
            this.G_D = LaserSensors.Signals["G_D"];
            this.G_A2 = LaserSensors.Signals["G_A2"];
            this.G_B2 = LaserSensors.Signals["G_B2"];
            this.G_C2 = LaserSensors.Signals["G_C2"];
            this.G_D2 = LaserSensors.Signals["G_D2"];

            this.I_A1 = MotA1.Signals["Ir"];
            this.I_A2 = MotA2.Signals["Ir"];
            this.I_B1 = MotB1.Signals["Ir"];
            this.I_B2 = MotB2.Signals["Ir"];
            this.I_C1 = MotC1.Signals["Ir"];
            this.I_C2 = MotC2.Signals["Ir"];
            this.I_D1 = MotD1.Signals["Ir"];
            this.I_D2 = MotD2.Signals["Ir"];
            this.I_Front = MotE1_Front.Signals["I_E1_Front"];
            this.I_Back = MotE2_Back.Signals["I_E2_Back"];
        }
        public bool SetLaneSwitch(double value)
    {
        Acquisition.ChangeSignalFromSignal(this.LaneSwitchSignal, value);
        return true;
    }

        public static void sendData (string dataType, string value)
        {
            Console.WriteLine("DATA:{0}:{1}", dataType, value);
        }
        public void getVerticalAirgaps ()
        {
            double[] airgapsList = { this.G_A.ValueDouble, this.G_B.ValueDouble, this.G_C.ValueDouble, this.G_D.ValueDouble };
            string[] gapStrings = { "G_A", "G_B", "G_C", "G_D" };
            int i = 0;
            foreach (string gapString in gapStrings)
            {
                string datatype = gapString.ToLower();
                string value = airgapsList[i].ToString();
                sendData(datatype, value);
                i++;
            }
        }

        public void getLateralAirgaps()
        {
            double[] airgapsList = { this.G_A2.ValueDouble, this.G_B2.ValueDouble, this.G_C2.ValueDouble, this.G_D2.ValueDouble };
            string[] gapStrings = { "G_A2", "G_B2", "G_C2", "G_D2" };
            int i = 0;
            foreach (string gapString in gapStrings)
            {
                string datatype = gapString.ToLower();
                string value = airgapsList[i].ToString();
                sendData(datatype, value);
                i++;
            }
        }

        public void getCurrents()
        {
            double[] currentList = { this.I_A1.ValueDouble, this.I_A2.ValueDouble, this.I_B1.ValueDouble, this.I_B2.ValueDouble, this.I_C1.ValueDouble, this.I_C2.ValueDouble, this.I_D1.ValueDouble, this.I_D2.ValueDouble, this.I_Front.ValueDouble, this.I_Back.ValueDouble};
            string[] currentStrings = { "I_A1", "I_A2", "I_B1", "I_B2", "I_C1", "I_C2", "I_D1", "I_D2", "I_EMS_AB", "I_EMS_CD"};
            int i = 0;
            foreach (string currentString in currentStrings)
            {
                string datatype = currentString.ToLower();
                string value = currentList[i].ToString();
                sendData(datatype, value);
                i++;
            }
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
public static void Main()
        {
            Levitation arcas = new Levitation();
           

  try
  {
                arcas.Initialize();

               /* Console.WriteLine("SampleCount: {0}", arcas.TopController.Signals["SampleCount"].ValueUint32);
*/

                /*    var axisControl = EnableAndMove.EnableAndMoveAxis(arcas.topController);*/

                /*    Acquisition.RunAcquisition(arcas.topController);*/
                while (true)
                {

                    try
                    {
                        string command = (InputsOutputs.ReadConsole());
                        arcas.ExecuteCommand(command);
                        arcas.getVerticalAirgaps();
                        arcas.getLateralAirgaps();
                        arcas.getCurrents();
                    }
                    catch (Exception)
                    {

                        Console.WriteLine("CRITICAL:loop_error");
                    }
                }
            }
  catch (PmpException ex)
  {
    Console.WriteLine("ERROR: {0}", ex.Message);
                Thread.Sleep(10000);

  }

  if (arcas.TopController != null)
  {
    arcas.TopController.Dispose(); 
  }

}
}
}