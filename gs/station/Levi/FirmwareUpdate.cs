using System;
using Pmp;

namespace PmpGettingStartedCs
{
internal class Firmware
{
public static void UpdateFirmware(ITopController topController)
{
  // Obtain topcontroller firmware updatable and print current version
  var fw = topController.Updatables["Firmware"];
  var fwVersion = fw.Version;

  Console.WriteLine("Controller {0} (PN: {1}, version: {2}.{3}.{4}.{5}-{6}).", 
                    topController.Name, fw.ProductNumber, fwVersion.Major, 
                    fwVersion.Minor, fwVersion.Patch, fwVersion.Build, fwVersion.Info);

  // Same for subcontrollers
  foreach (var subctrl in topController.Controllers)
  {
    var controller = subctrl.Value;
    try
    {
      var scFw = controller.Updatables["Firmware"];

      try
      {
        var scFwVersion = scFw.Version;
        Console.WriteLine("Controller {0} (PN: {1}, version: {2}.{3}.{4}.{5}).",
                          controller.Name, scFw.ProductNumber, scFwVersion.Major,
                          scFwVersion.Minor, scFwVersion.Patch, scFwVersion.Build);
      }
      catch (UnsupportedException)
      {
        Console.WriteLine("Firmware updatable of controller {0} does not have a version.", controller.Name);
      }
    }
    catch (InvalidArgumentException)
    {
      Console.WriteLine("Firmware updatable of controller {0} is not available.", controller.Name);
    }
  }

  // Update firmware
  var firmwareFile = "../../example_files/bin/myFirmwareFile.bin";
  Console.WriteLine("Update firmware of {0}.", fw.FullName);
  fw.LoadContentsFromFile(firmwareFile);

  fw.WaitComplete(60 * 5);
  Console.WriteLine("Firmware update of {0} completed.", fw.FullName);

  // Reboot controller
  if (topController.IsSimulated)
    return; // Skip reboot in case of simulator.

  // Top-controllers can only be rebooted in 'Config' state
  topController.Stop();

  Console.WriteLine("Reboot controller {0}.", topController.Name);
  topController.Reboot();
}
}
}
