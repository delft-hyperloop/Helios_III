import os
import sys
import csv
import matplotlib.pyplot as plt
from collections import defaultdict

def read_csv(file_path):
    data = defaultdict(list)
    with open(file_path, 'r') as file:
        reader = csv.reader(file, delimiter=';')
        headers = next(reader)
        for row in reader:
            for header, value in zip(headers, row):
                data[header].append(float(value) if value.replace('.', '', 1).isdigit() else value)
    return headers, data

def plot_data(headers, data, title, colors=None):
    if colors is None:
        colors = [None] * (len(headers) - 1)
        
    if len(headers) == 2:
        plt.plot(data[headers[0]], data[headers[1]], label=title, color=colors[0])
        plt.grid(True)
    else:
        fig, axs = plt.subplots(len(headers) - 1, 1, figsize=(10, 8))
        fig.suptitle(title)
        for i, (header, color) in enumerate(zip(headers[1:], colors), 1):
            axs[i-1].plot(data[headers[0]], data[header], color=color)
            axs[i-1].set_title(header)
            axs[i-1].grid(True)
        plt.tight_layout()
        plt.show()

def parse_input_arguments(args):
    groups = args.split('|')
    parsed_groups = []
    for group in groups:
        entries = group.split('&')
        parsed_entries = []
        for entry in entries:
            parts = entry.split(':')
            if len(parts) == 3:
                parsed_entries.append((parts[0], parts[1], parts[2]))
            else:
                parsed_entries.append((parts[0], parts[1], None))
        parsed_groups.append(parsed_entries)
    return parsed_groups

def main():
    if len(sys.argv) < 3:
        print("Usage: python script.py <path> <node> <object-entry-name> | <path> <grouped-object-entries>")
        return

    path = sys.argv[1]
    
    if len(sys.argv) == 4:
        # Simple format: <path> <node> <object-entry-name>
        node = sys.argv[2]
        object_entry_name = sys.argv[3]
        file_path = os.path.join(path, node, f"{object_entry_name}.csv")
        if not os.path.isfile(file_path):
            file_path = os.path.join(path, f"{object_entry_name}.csv")
        if not os.path.isfile(file_path):
            print(f"File {file_path} not found!")
            return
        
        headers, data = read_csv(file_path)
        plot_data(headers, data, f"{node} - {object_entry_name}")
        plt.legend()
        plt.show()
    else:
        # Complex format: <path> <grouped-object-entries>
        grouped_object_entries = sys.argv[2]
        parsed_groups = parse_input_arguments(grouped_object_entries)
        
        for group in parsed_groups:
            for entry in group:
                node, object_entry_name, color = entry
                file_path = os.path.join(path, node, f"{object_entry_name}.csv")
                if not os.path.isfile(file_path):
                    file_path = os.path.join(path, f"{object_entry_name}.csv")
                if not os.path.isfile(file_path):
                    print(f"File {file_path} not found!")
                    continue

                headers, data = read_csv(file_path)
                colors = [color] if len(headers) == 2 else [color] * (len(headers) - 1)
                plot_data(headers, data, f"{node} - {object_entry_name}", colors=colors)

            plt.legend()
            plt.show()

if __name__ == "__main__":
    main()