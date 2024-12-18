using System;
using System.Collections.Generic;
using System.Linq;
using Pmp;

namespace PmpGettingStartedCs
{
internal class EnableAndMove
{
public static string RunStateCommand(ICommandQueue commandQueue, List<CommandType> commandTypes)
{

  var sequence = commandQueue.CreateCommandSequence(commandTypes);
  commandQueue.Queue(sequence);

  sequence.WaitComplete(10.0);

  if (sequence.State == CommandState.Failed)
  {
    var msg = sequence.FailedCommands.First().RunException;
                return "error";
            }
            else
            {
                return "on";
            }
}

public static void EnableAxis(Levitation arcas)
{


            try
            {

                // Enable axis
                arcas.VerticalAxis.ResetFault();
                arcas.VerticalQueue.Clear();
                string result = RunStateCommand(arcas.VerticalQueue, new List<CommandType> { CommandType.Shutdown, CommandType.EnableOperation });
                Console.WriteLine("INFO:vertical_{0}", result);
            }
            catch (Exception)
            {
                Console.WriteLine("ERROR:vertical_error");
            }

            try
            {
                arcas.LateralAxis.ResetFault();
                arcas.LateralQueue.Clear();
                string result = RunStateCommand(arcas.LateralQueue, new List<CommandType> { CommandType.Shutdown, CommandType.EnableOperation });
                Console.WriteLine("INFO:lateral_{0}", result);
            }
            catch (Exception)
            {
                Console.WriteLine("ERROR:lateral_error");
            }

        }

        public static void DisableAxis(Levitation arcas)
        {
            try
            {
                string result = RunStateCommand(arcas.VerticalQueue, new List<CommandType> { CommandType.DisableVoltage });
                if (result == "on")
                {
                    Console.WriteLine("INFO:vertical_{0}", "off"); 
                }
                else
                {
                    Console.WriteLine("ERROR:vertical_error");
                }
            }
            catch (Exception)
            {
                Console.WriteLine("ERROR:vertical_error");
            }

            try
            {
                string result = RunStateCommand(arcas.LateralQueue, new List<CommandType> { CommandType.DisableVoltage });
                if (result == "on")
                {
                    Console.WriteLine("INFO:lateral_{0}", "off");
                }
                else
                {
                    Console.WriteLine("ERROR:lateral_error");
                }
            }
            catch (Exception)
            {

                Console.WriteLine("ERROR:lateral_error");
            }
        }
    }
}
