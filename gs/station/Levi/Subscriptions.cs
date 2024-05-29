using System;
using Pmp;

namespace PmpGettingStartedCs
{
internal class Subscriptions
{
public static string CurrentDateTime()
{
  return DateTime.Now.ToString("HH:mm:ss");
}

public static void LogEvent(IEvent ev)
{
  try
  {
    Console.WriteLine("{0}: Event triggered: {1}.", CurrentDateTime(), ev.FullName);
  }
  catch (Exception e)
  {
    Console.WriteLine("Error while logging event. Message: {0}", e.Message);
  }
}

public static void LogEventResponse(IEventResponse resp, IEvent ev)
{
  try
  {
    Console.WriteLine("{0}: Event response {1} triggered due to {2}.", CurrentDateTime(), resp.FullName, ev.FullName);
  }
  catch (Exception e)
  {
    Console.WriteLine("Error while logging event response. Message: {0}", e.Message);
  }
}

public static void LogRootError(IEvent ev)
{
  try
  {
    Console.WriteLine("{0}: Root error: {1}.", CurrentDateTime(), ev.FullName);
  }
  catch (Exception e)
  {
    Console.WriteLine("Error while logging root error. Message: {0}", e.Message);
  }
}

public static void SubscriptionExample(IController topController, IAxisControl axisControl)
{
  // Subscribe to an event
  var ev = topController.Events["SampleOverload"];

  var eventOccuredCallback = new EventOccurredHandler((IEvent e, string str) => { LogEvent(e); });
  var subscription = ev.Subscribe(eventOccuredCallback);
  Console.WriteLine("Subscribed to {0}.", ev.FullName);

  subscription.Unsubscribe();
  Console.WriteLine("Unsubscribed from {0}.", ev.FullName);

  // Subscribe to an event response
  var response = axisControl.Responses["ErrorResponse"];

  var responseHandler = new EventResponseHandler((IEventResponse resp, IEvent e) => { LogEventResponse(resp, e); });
  var responseSubscription = response.Subscribe(responseHandler);
  Console.WriteLine("Subscribed to {0}.", response.FullName);

  responseSubscription.Unsubscribe();
  Console.WriteLine("Unsubscribed from {0}.", response.FullName);

  // Subscribe to the root error of an axiscontrol
  var rooterrorOccurredHandler = new EventOccurredHandler((IEvent e, string str) => { LogRootError(e); });
  var rootErrorSubscription = axisControl.SubscribeRootError(rooterrorOccurredHandler);
  Console.WriteLine("Subscribed to root error of {0}.", axisControl.FullName);

  rootErrorSubscription.Unsubscribe();
  Console.WriteLine("Unsubscribed from root error of {0}.", axisControl.FullName);
}
}
}