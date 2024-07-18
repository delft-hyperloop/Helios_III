use std::collections::BTreeMap;

use gslib::Location::BackwardsA;
use gslib::Location::BackwardsB;
use gslib::Location::BackwardsC;
use gslib::Location::BrakeHere;
use gslib::Location::ForwardA;
use gslib::Location::ForwardB;
use gslib::Location::ForwardC;
use gslib::Location::LaneSwitchCurved;
use gslib::Location::LaneSwitchStraight;
use gslib::Location::StopAndWait;
use gslib::Route;

pub fn validate_route_internal(r: Route) -> bool {
    let a = r.current_position != 0;

    let b = r.speeds.0.contains_key(&ForwardA)
        && r.speeds.0.contains_key(&ForwardB)
        && r.speeds.0.contains_key(&ForwardC)
        && r.speeds.0.contains_key(&BackwardsA)
        && r.speeds.0.contains_key(&BackwardsB)
        && r.speeds.0.contains_key(&BackwardsC)
        && r.speeds.0.contains_key(&LaneSwitchCurved)
        && r.speeds.0.contains_key(&LaneSwitchStraight);

    let c = r.speeds.0.get(&StopAndWait).map_or(false, |y| y.eq(&0))
        && r.speeds.0.get(&BrakeHere).map_or(false, |y| y.eq(&0));

    // todo: statically generate this DAG with a procedural macro from the FSM code
    let allowed_previous = BTreeMap::from([
        (ForwardA, vec![StopAndWait, BrakeHere, BackwardsA]),
        (ForwardB, vec![BackwardsB, LaneSwitchStraight, StopAndWait, BrakeHere]),
        (ForwardC, vec![BackwardsC, LaneSwitchCurved, StopAndWait, BrakeHere]),
        (BackwardsA, vec![ForwardA, LaneSwitchCurved, LaneSwitchStraight, StopAndWait, BrakeHere]),
        (BackwardsB, vec![ForwardB, StopAndWait, BrakeHere]),
        (BackwardsC, vec![ForwardC, StopAndWait, BrakeHere]),
        (LaneSwitchStraight, vec![ForwardA, BackwardsB, StopAndWait, BrakeHere]),
        (LaneSwitchCurved, vec![ForwardA, BackwardsC, StopAndWait, BrakeHere]),
        (
            StopAndWait,
            vec![
                ForwardA,
                ForwardB,
                ForwardC,
                BackwardsA,
                BackwardsB,
                BackwardsC,
                LaneSwitchCurved,
                LaneSwitchStraight,
                StopAndWait,
                BrakeHere,
            ],
        ),
        (
            BrakeHere,
            vec![
                ForwardA,
                ForwardB,
                ForwardC,
                BackwardsA,
                BackwardsB,
                BackwardsC,
                LaneSwitchCurved,
                LaneSwitchStraight,
                StopAndWait,
                BrakeHere,
            ],
        ),
    ]);
    let mut prev = BrakeHere;
    let d = r.positions.into_iter().fold(true, |acc, p| {
        let temp = prev;
        prev = p;
        acc && allowed_previous.get(&p).map_or(false, |v| v.contains(&temp))
    });

    a && b && c && d
}
