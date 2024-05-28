using System;
using System.Linq;
using System.Threading;
using Pmp;

namespace PmpGettingStartedCs
{
internal class Acquisition
{

public static bool ChangeSignalFromPath(ITopController topController, string signalName, double value)
    {
        ISignal sig = topController.Signals[signalName];
        sig.ValueDouble = value;
        return true;
    }

public static bool ChangeSignalFromSignal(ISignal signal, double value)
    {
        signal.ValueDouble = value;
        return true;
    }
public static void RunAcquisition(ITopController topController)
{
  // Prepare acq and add signals
  var acq = topController.ReserveAcquisition();


    // Load all relevant Signals
    var processingBlocks = topController.ProcessingBlocks;
    var controllers = topController.Controllers;
    var VerticalController = processingBlocks["Airgap_controllers"];
    var LateralController = processingBlocks["LateralController"];
    var LaserSensors = processingBlocks["LaserSensors"];

    // Define the Cygni
    var CygnusA = topController.Controllers["Cygnus A"];
    var CygnusB = topController.Controllers["Cygnus B"];
    var CygnusC = topController.Controllers["Cygnus C"];
    var CygnusD = topController.Controllers["Cygnus D"];
    var CygnusE = topController.Controllers["Cygnus E"];

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
            var Motor_Enabled = VerticalController.Signals["PropulsionOn"];
            //At_Top = FSM.Signals["At_Top"];
            //Reset = FSM_Feedthrough.Signals["Reset"];
            var G_A = LaserSensors.Signals["G_A"];
            var G_B = LaserSensors.Signals["G_B"];
            var G_C = LaserSensors.Signals["G_C"];
            var G_D = LaserSensors.Signals["G_D"];
            var G_A2 = LaserSensors.Signals["G_A2"];
            var G_B2 = LaserSensors.Signals["G_B2"];
            var G_C2 = LaserSensors.Signals["G_C2"];
            var G_D2 = LaserSensors.Signals["G_D2"];

            var I_A1 = MotA1.Signals["Ir"];
            var I_A2 = MotA2.Signals["Ir"];
            var I_B1 = MotB1.Signals["Ir"];
            var I_B2 = MotB2.Signals["Ir"];
            var I_C1 = MotC1.Signals["Ir"];
            var I_C2 = MotC2.Signals["Ir"];
            var I_D1 = MotD1.Signals["Ir"];
            var I_D2 = MotD2.Signals["Ir"];
            var I_Front = MotE1_Front.Signals["I_E1_Front"];
            var I_Back = MotE2_Back.Signals["I_E2_Back"];

            var Levi_State_Vert = VerticalController.Signals["OperatingMode"];
            var Levi_State_Lat = LateralController.Signals["OperatingMode"];

            acq.Signals.Add(G_A);
            acq.Signals.Add(G_B);
            acq.Signals.Add(G_C);
            acq.Signals.Add(G_D);
            acq.Signals.Add(G_A2);
            acq.Signals.Add(G_B2);
            acq.Signals.Add(G_C2);
            acq.Signals.Add(G_D2);

            // Add Offcenternesses to the acq
            //acq.Signals.Add(Lateral_Controller_Front.Signals["Offcenterness"]);
            //acq.Signals.Add(Lateral_Controller_Back.Signals["Offcenterness"]);

            // Add output currents to the acq
            acq.Signals.Add(I_A1);
            acq.Signals.Add(I_A2);
            acq.Signals.Add(I_B1);
            acq.Signals.Add(I_B2);
            acq.Signals.Add(I_C1);
            acq.Signals.Add(I_C2);
            acq.Signals.Add(I_D1);
            acq.Signals.Add(I_D2);
            acq.Signals.Add(I_Front);
            acq.Signals.Add(I_Back);


            //VBus_A = FSM.Signals["Vbus_A"];
            //VBus_B = FSM.Signals["Vbus_B"];
            //VBus_C = FSM.Signals["Vbus_C"];
            //VBus_D = FSM.Signals["Vbus_D"];
            //VBus_E = FSM.Signals["Vbus_E"];



            // Start acq
            var acqSink = acq.ReserveAcqSink(-1, AcqSinkMode.DiscardOldSamples);
  acq.Prepare();
  acq.Start();
  Console.WriteLine("Start Acquisition.");

  // Perform action
  Thread.Sleep(1000);

  // Stop acq
  acq.Stop();
  Console.WriteLine("Stop Acquisition.");

  acqSink.WaitComplete(30);
  Console.WriteLine("Wait for AcquisitionSink to complete.");

  var acqTraceFile = "myacqTrace.msf";

  Console.WriteLine("Save acq trace to file: {0}.", acqTraceFile);
  acqSink.WriteToFile(AcqFileFormat.Msf, acqTraceFile);
}
}
}