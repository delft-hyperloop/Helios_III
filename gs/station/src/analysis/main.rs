use anyhow::Result;
use gslib::Datatype;
use gslib::Log;
use gslib::Message;
use gslib::ProcessedData;

fn main() -> Result<()> {
    let x = std::fs::read_to_string("/Users/andtsa/downloads/logs_scrut.txt")?;
    let y: Log = serde_json::from_str(&x)?;

    let z = y
        .messages
        .iter()
        .filter(|x| {
            matches!(x, Message::Data(ProcessedData { datatype: Datatype::BatteryCurrentHigh, .. }))
        })
        .collect::<Vec<&Message>>();

    let w = z
        .iter()
        .filter_map(|x| match x {
            Message::Data(y) => Some((y.value, y.timestamp)),
            _ => None,
        })
        .collect::<Vec<(f64, u64)>>();

    std::fs::write(
        "/Users/andtsa/downloads/out.csv",
        w.iter().map(|(a, b)| format!("{},{}", b, a)).collect::<Vec<String>>().join("\n"),
    )?;

    Ok(())
}
