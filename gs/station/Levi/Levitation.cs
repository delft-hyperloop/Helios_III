using System;
using System.Net;
using System.Linq;
using Pmp;
using System.Threading;
using System.IO;
using System.Threading.Tasks;
using static Pmp.Unmanaged.Abi;

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

        public ISignal Pitch { set; get; }

        public ISignal Roll { set; get; }

        public ISignal Airgap { set; get; }

        public ISignal Motor_Enabled { set; get; }

        public ISignal Power_Vert { set; get; }
        public ISignal Power_Lat { set; get; }

        public ISignal Volt_A { set; get; }
        public ISignal Volt_B { set; get; }
        public ISignal Volt_C { set; get; }
        public ISignal Volt_D { set; get; }
        public ISignal Volt_E { set; get; }

        public ISignal VerticalZeroResetSignal { set; get; }
        public ISignal LateralZeroResetSignal { set; get; }

        public ISignal SenseconLocation { set; get; }
        public ISignal LS_signal { set; get; }
        public ISignal PropulsionCurrent { set; get; }

        public ISignal LeviLocation { set; get; }
        public ISignal LeviSpeed { set; get; }


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
                        Console.WriteLine("INFO:disabling_control_loop\n");
                        SetVerticalMode(0);
                        SetLateralMode(0);
                        Console.WriteLine("INFO:enabling_levi_HV\n");
                        EnableAndMove.EnableAxis(this);

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ERROR:axis_not_turning_on\n");
                    }
                    break;

                case "disable_axis":
                    try
                    {
                        Console.WriteLine("INFO:disabling_levi_HV\n");
                        EnableAndMove.DisableAxis(this);
                        Console.WriteLine("INFO:disabling_control_loop\n");
                        SetVerticalMode(2);
                        SetLateralMode(2);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:axis_not_turning_off\n");
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
                        Thread.Sleep(3000);
                        this.SetLateralMode(1);
                        Thread.Sleep(1000);
                        Console.Write("INFO:launch_complete\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "vert_mode_normal":
                    try
                    {
                        this.SetVerticalMode(0);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "vert_mode_offsets":
                    try
                    {
                        this.SetVerticalMode(5);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "vert_mode_dance":
                    try
                    {
                        this.SetVerticalMode(6);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "vert_mode_sine":
                    try
                    {
                        this.SetVerticalMode(7);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "vert0":
                    try
                    {
                        this.SetVerticalZeroReset(0);
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
/*
                case "LeviStartLS":
                    try
                    {
                        this.SetLS_Signal(1);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;*/

/*                case "LeviStopLS":
                    try
                    {
                        this.SetLS_Signal(0);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;
*/
                case "vert0_reset":
                    try
                    {
                        this.SetVerticalZeroReset(1);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "lat0_reset":
                    try
                    {
                        this.SetLateralZeroReset(1);
                        Thread.Sleep(50);
                        this.SetLateralZeroReset(0);
                        Console.Write("INFO:mode_set\n");
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:mode_error\n");
                    }
                    break;

                case "lat_mode_normal":
                    try
                    {
                        this.SetLateralMode(1);
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
                        this.SetVerticalMode(3);
                        Console.Write("INFO:landing\n");
                        Thread.Sleep(5000);
                        this.SetLateralMode(2);
                        Thread.Sleep(5000);
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

                case "LeviPropulsionStart":
                    try
                    {
                        this.SetPropulsion(1);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:set_signal_error\n");
                    }
                    break;

                case "LeviPropulsionStop":
                    try
                    {
                        this.SetPropulsion(0);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("CRITICAL:set_signal_error\n");
                    }
                    break;

                case "EmergencyBrake":
                    try
                    {
                        Console.WriteLine("INFO:disabling_control_loop\n");
                        SetVerticalMode(2);
                        SetLateralMode(2);
                        Console.WriteLine("INFO:discharging_HV\n");
                        Thread.Sleep(500);
                        EnableAndMove.EnableAxis(this);

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ERROR:not_discharging_HV\n");
                    }
                    break;

                case "LeviEmergencyBrake":
                    try
                    {
                        Console.WriteLine("INFO:disabling_control_loop\n");
                        SetVerticalMode(2);
                        SetLateralMode(2);
                        Console.WriteLine("INFO:discharging_HV\n");
                        Thread.Sleep(500);
                        EnableAndMove.EnableAxis(this);

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ERROR:not_discharging_HV\n");
                    }
                    break;

                case "StopHV":
                    try
                    {
                        Console.WriteLine("INFO:disabling_control_loop\n");
                        SetVerticalMode(2);
                        SetLateralMode(2);
                        Console.WriteLine("INFO:discharging_HV\n");
                        Thread.Sleep(500);
                        EnableAndMove.EnableAxis(this);

                    }
                    catch (Exception)
                    {
                        Console.WriteLine("ERROR:not_discharging_HV\n");
                    }
                    break;


               /* case string data_str when data_str.Contains("data:"):
                    try
                    {
                        data_str = data_str.Trim();
                        char[] seperator = { ':' };
                        string[] data_list = data_str.Split(seperator,
                                                            StringSplitOptions.RemoveEmptyEntries);
                        string data_id = data_list[1];
                        double data_value = Convert.ToDouble(data_list[2]);
                        if (data_id.ToLower().Contains("propulsioncurrent"))
                        {
                            this.SetPropulsionCurrent(data_value);
                        }
                        else if (data_id.ToLower().Contains("localisation"))
                        {
                            this.SetSenseconLocation(data_value/1000);
                        }
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("WARNING:receive_data_error\n");
                    }
                    break;*/

                default:
/*                    Console.WriteLine("WARNING:invalid\n");*/
                    break;

            }
        }
        public void SetPaths()
        {
            this.FilePath = Directory.GetCurrentDirectory();
            /*            this.FilePath = Directory.GetParent(FilePath).FullName;*/
            this.FilePath = this.FilePath + "\\Levi";
            this.ConfigPath = this.FilePath + "\\levitation_config_file.xml";
            this.CouplerPath = this.FilePath + "\\00000002_044c2c52_0012.xml";
            this.BusPath = this.FilePath + "\\00000002_0c203052_0014.xml";
            Console.WriteLine(this.ConfigPath.ToString());

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

            this.Offset_AB = LateralController.Signals["OffsetFront"];
            this.Offset_CD = LateralController.Signals["OffsetBack"];

/*            this.SenseconLocation = LateralController.Signals["x_location_raw"];
            this.LeviLocation = LateralController.Signals["x_location"];
            this.LeviSpeed = LateralController.Signals["x_speed"];
            this.LS_signal = LateralController.Signals["LS_signal"];*/
            this.PropulsionCurrent = VerticalController.Signals["PropulsionCurrent"];

            this.Airgap = VerticalController.Signals["Airgap"];
            this.Pitch = VerticalController.Signals["Pitch"];
            this.Roll = VerticalController.Signals["Roll"];
            this.Power_Vert = VerticalController.Signals["Power_avg"];
            this.Power_Lat = LateralController.Signals["Power_Lat_avg"];

            /*            this.VerticalZeroResetSignal = VerticalController.Signals["Undo_0current"];
                        this.LateralZeroResetSignal = LateralController.Signals["lat_zero_reset"];*/


            this.Volt_A = CygnusA.Sensors["VBus"].Signals["Voltage"];
            this.Volt_B = CygnusB.Sensors["VBus"].Signals["Voltage"];
            this.Volt_C = CygnusC.Sensors["VBus"].Signals["Voltage"];
            this.Volt_D = CygnusD.Sensors["VBus"].Signals["Voltage"];
            this.Volt_E = CygnusE.Sensors["VBus"].Signals["Voltage"];

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

        public bool SetVerticalZeroReset(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.VerticalZeroResetSignal, value);
            return true;
        }

        public bool SetLateralZeroReset(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.LateralZeroResetSignal, value);
            return true;
        }

        public bool SetPropulsion(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.Motor_Enabled, value);
            return true;
        }

        public bool SetPropulsionCurrent(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.PropulsionCurrent, value);
            return true;
        }

        public bool SetSenseconLocation(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.SenseconLocation, value);
            return true;
        }

        public bool SetLS_Signal(double value)
        {
            Acquisition.ChangeSignalFromSignal(this.LS_signal, value);
            return true;
        }

        public static void sendData(string dataType, string value)
        {
            Console.WriteLine("DATA:{0}:{1}", dataType, value);
        }
        public void getVerticalAirgaps()
        {
            double[] airgapsList = { this.G_A.ValueDouble * 1000, this.G_B.ValueDouble * 1000, this.G_C.ValueDouble * 1000, this.G_D.ValueDouble * 1000 };
            string[] gapStrings = { "levi_hems_gap_a", "levi_hems_gap_b", "levi_hems_gap_c", "levi_hems_gap_d" };
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
            double[] airgapsList = { this.G_A2.ValueDouble * 1000, this.G_B2.ValueDouble * 1000, this.G_C2.ValueDouble * 1000, this.G_D2.ValueDouble * 1000 };
            string[] gapStrings = { "levi_ems_gap_a", "levi_ems_gap_b", "levi_ems_gap_c", "levi_ems_gap_d" };
            int i = 0;
            foreach (string gapString in gapStrings)
            {
                string datatype = gapString.ToLower();
                string value = airgapsList[i].ToString();
                sendData(datatype, value);
                i++;
            }
        }

        public void getDegreesOfFreedom()
        {
            double[] airgapsList = { this.Airgap.ValueDouble, this.Pitch.ValueDouble, this.Roll.ValueDouble, this.Offset_AB.ValueDouble, this.Offset_CD.ValueDouble };
            string[] gapStrings = { "levi_hems_airgap", "levi_hems_pitch", "levi_hems_roll", "levi_ems_offset_ab", "levi_ems_offset_cd" };
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
            double[] currentList = { this.I_A1.ValueDouble, this.I_A2.ValueDouble, this.I_B1.ValueDouble, this.I_B2.ValueDouble, this.I_C1.ValueDouble, this.I_C2.ValueDouble, this.I_D1.ValueDouble, this.I_D2.ValueDouble, this.I_Front.ValueDouble, this.I_Back.ValueDouble, this.Power_Vert.ValueDouble, this.Power_Lat.ValueDouble };
            string[] currentStrings = { "levi_hems_current_a1", "levi_hems_current_a2", "levi_hems_current_b1", "levi_hems_current_b2", "levi_hems_current_c1", "levi_hems_current_c2", "levi_hems_current_d1", "levi_hems_current_d2", "levi_ems_current_ab", "levi_ems_current_cd", "levi_hems_power", "levi_ems_power" };
            int i = 0;
            foreach (string currentString in currentStrings)
            {

                string datatype = currentString.ToLower();
                string value = currentList[i].ToString();
                sendData(datatype, value);
                i++;
            }
        }

        public void getVoltages()
        {
            double[] voltageList = { this.Volt_A.ValueDouble, this.Volt_B.ValueDouble, this.Volt_C.ValueDouble, this.Volt_D.ValueDouble, this.Volt_E.ValueDouble };
            double[] editedVoltageList = { voltageList.Average(), voltageList.Min(), voltageList.Max() };
            string[] editedVoltageStrings = { "levi_volt_avg", "levi_volt_min", "levi_volt_max" };
            string[] voltageStrings = { "levi_volt_A", "levi_volt_B", "levi_volt_C", "levi_volt_D", "levi_volt_E" };
            int i = 0;
            foreach (string voltageString in editedVoltageStrings)
            {
                string datatype = voltageString.ToLower();
                string value = editedVoltageList[i].ToString();
                sendData(datatype, value);
                i++;
            }
            i = 0;
            foreach (string voltageString in voltageStrings)
            {
                string datatype = voltageString.ToLower();
                string value = voltageList[i].ToString();
                sendData(datatype, value);
                i++;
            }
        }

        public void getLocalization()
        {
            double[] localizationList = { this.LeviLocation.ValueDouble*1000, this.LeviSpeed.ValueDouble };
            string[] localizationStrings = { "levi_location", "levi_speed" };
            int i = 0;
            foreach (string localizationString in localizationStrings)
            {
                string datatype = localizationString.ToLower();
                string value = localizationList[i].ToString();
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
            try
            {
                this.SetNameAdress();
                this.SetPaths();
                this.TopController = ControllerDiscoveryAndInit.DiscoveryAndInit(this);
            }
            catch (Exception)
            {
                Console.WriteLine("WARNING:init_error");
            }
            try
            {
                this.SetSignals();
            }
            catch (Exception)
            {
                Console.WriteLine("WARNING:init_signal_error");
            }
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
                Task.Run(() => {
                    while (true)
                    {
                        try
                        {
                            string command = (InputsOutputs.ReadConsole());
                            arcas.ExecuteCommand(command);
                        }
                        catch (Exception)
                        {
                            Console.WriteLine("CRITICAL:loop_error");
                        }
                        // Do something with the input. Maybe switch or if/else statement?
                    }
                });
                while (true)
                {

                    try
                    {
                        try
                        {
                            arcas.getVoltages();
                        }
                        catch (Exception)
                        {
                            Console.WriteLine("CRITICAL:NO_LEVI_VOlTAGE_DATA");
                        }
                        Thread.Sleep(50);
                        /*                        arcas.getVerticalAirgaps();
                                                arcas.getLateralAirgaps();
                                                arcas.getCurrents();
                                                arcas.getDegreesOfFreedom();*/

                        /*                        arcas.getLocalization();*/

                    }
                    catch (Exception)
                    {

                        Console.WriteLine("WARNING:cant_receive_data");
                    }
                }
            }
            catch (PmpException ex)
            {
                Console.WriteLine("CRITICAL:broke_loop");
                Thread.Sleep(10000);

            }

            if (arcas.TopController != null)
            {
                arcas.TopController.Dispose();
            }

        }
    }
}