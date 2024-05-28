using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using Pmp;

namespace PmpGettingStartedCs
{
internal class ControllerDiscoveryAndInit
{
public static void SetRun(Levitation arcas)
{
    // Set top-controller state to run
    Console.WriteLine("Setting top-controller to run.");
    arcas.TopController.Run();
    Console.WriteLine("Initialization complete.");
        }

public static void ApplyConfig(Levitation arcas)
{
    Console.WriteLine("Loading configuration file {0}.", arcas.ConfigPath);
    try
    {
        ITopController topController = arcas.TopController;
        string config = arcas.ConfigPath;
        
        topController.LoadConfigurationFromFile(config);
        Console.WriteLine("Config loaded sucessfuly");
    }
    catch (PmpException ex)
    {
        Console.WriteLine("Error occurred when applying config {0}.", ex);
        Thread.Sleep(2000);
    }
}

    

public static ITopController DiscoveryAndInit(Levitation arcas)
{
  var topController = DiscoverTopController(arcas);
  Initialize(arcas, topController, true, true);
  return topController;
}

/*public static ITopController CreateSimulatorAndInit()
{
  var myAddress = "localhost";
  var myTopControllerName = "MyTopController";

  var topController = StartSimulator(myAddress, myTopControllerName);
  Initialize(topController);
  return topController;
}*/

public static ITopController DiscoverTopController(Levitation arcas)
{
  Console.WriteLine("Trying to discover {0} on {1}.", arcas.Name, arcas.Address);
  var system = new Pmp.System(arcas.Address);

  var controllers = system.Controllers.Values.ToArray();
  while (controllers.Length == 0)
  {
    system.Discover();
    Thread.Sleep(100);
    controllers = system.Controllers.Values.ToArray();
  }

  var topController = system.Controllers[arcas.Name];
  Console.WriteLine("Discovered controller {0} on address {1}.", topController.Name, topController.Address);

  // Check compatibility
  if (topController.IsSimulated)
    Console.WriteLine("Controller {0} is simulated.", arcas.Name);

  if (topController.IsBackupRunning)
    Console.WriteLine("Controller {0} is running backup firmware.", arcas.Name);

  if (!topController.IsCompatible)
    Console.WriteLine("Controller {0} is not compatible with the current client version.", arcas.Name);

  if (topController.IsCompatible && !topController.IsBackupRunning)
    Console.WriteLine("Controller {0} is compatible and not running backup firmware.", arcas.Name);
  arcas.TopController = topController;
  return topController;
}

/*public static ITopController StartSimulator(string myAddress, string myTopControllerName)
{
  // for windows the model xml files can be found in "<PMP install directory>/<version>/model"

  var controllerModel = "../../example_files/model/example_topcontroller.xml";
  var subcontrollerModel = "../../example_files/model/example_subcontroller.xml";

  // create system controller
  var system = new Pmp.System(myAddress);

*//*  SimulatorSettings simulatorSettings = new SimulatorSettings();
  simulatorSettings.Address = myAddress;
  simulatorSettings.CpuUtilization = CpuUtilization.Modest;
  simulatorSettings.RealTimeThreads = 1;
  simulatorSettings.SpeedFactor = 1;

  system.CreateControllerFromFile(controllerModel, "12-34-567-000", 0, simulatorSettings);*//*

  var topController = DiscoverTopController(myAddress, myTopControllerName);

  // create subcontroller
  topController.CreateControllerFromFile(subcontrollerModel, "12-34-567-100", 0);

  Thread.Sleep(1000); // wait until controllers are booted
*//*
  return topController;*//*
}*/
public static void Reboot(Levitation arcas)
        {
            arcas.TopController.Stop();
            arcas.TopController.Reboot();
        }
public static void Initialize(Levitation arcas, ITopController topController, bool applyModel, bool applyConfig) 
{
  Console.WriteLine("Wait for top-controller to reach Config.");
  topController.WaitState(TopControllerState.Config, 10);

  // Print information of subcontrollers
  var subControllers = topController.Controllers;

  Console.WriteLine("Found {0} sub-controllers: {1}.", subControllers.Count(), string.Join(", ", subControllers.Keys));


    if (applyModel)
    {
        try
        {
            ISubController CouplerVert = subControllers["Unknown-slave-EtherCAT:0.5"];
            CouplerVert.ApplyModelFromFile(arcas.CouplerPath);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error occurred when applying Vertical Coupler Model {0}.", ex);
        }
        try
        {
            ISubController CouplerLat = subControllers["Unknown-slave-EtherCAT:0.7"];
            CouplerLat.ApplyModelFromFile(arcas.CouplerPath);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error occurred when applying Lateral Coupler Model {0}.", ex);
        }

        try
        {
            ISubController BusVert = subControllers["Unknown-slave-EtherCAT:0.6"];
            BusVert.ApplyModelFromFile(arcas.BusPath);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error occurred when applying Vertical Bus Model {0}.", ex);
        }
        try
        {
            ISubController BusLat = subControllers["Unknown-slave-EtherCAT:0.8"];
            BusLat.ApplyModelFromFile(arcas.BusPath);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error occurred when applying Lateral Bus Model {0}.", ex);
            Thread.Sleep(2000);
        } 
    }
    if (applyConfig)
    {
        ApplyConfig(arcas);
    }
    SetRun(arcas);
   /* var x = topController.Buses;*/
        }
}
}
