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
  Console.WriteLine("Queueing a command sequence [ {0} ] on {1}.", string.Join(", ", commandTypes), commandQueue.FullName);

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
                Console.WriteLine("vertical_{0}", result);
            }
            catch (Exception)
            {
                Console.WriteLine("vertical_error");
            }

            try
            {
                arcas.LateralAxis.ResetFault();
                arcas.LateralQueue.Clear();
                string result = RunStateCommand(arcas.LateralQueue, new List<CommandType> { CommandType.Shutdown, CommandType.EnableOperation });
                Console.WriteLine("lateral_{0}", result);
            }
            catch (Exception)
            {
                Console.WriteLine("lateral_error");
            }

        }

        public static void DisableAxis(Levitation arcas)
        {
            try
            {
                string result = RunStateCommand(arcas.VerticalQueue, new List<CommandType> { CommandType.DisableVoltage });
                if (result == "on")
                {
                    Console.WriteLine("vertical_{0}", "off"); 
                }
                else
                {
                    Console.WriteLine("vertical_error");
                }
            }
            catch (Exception)
            {
                Console.WriteLine("vertical_error");
            }

            try
            {
                string result = RunStateCommand(arcas.LateralQueue, new List<CommandType> { CommandType.DisableVoltage });
                if (result == "on")
                {
                    Console.WriteLine("lateral_{0}", "off");
                }
                else
                {
                    Console.WriteLine("lateral_error");
                }
            }
            catch (Exception)
            {

                Console.WriteLine("lateral_error");
            }
        }
    }
}
