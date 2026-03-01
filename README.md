# Zork!

A classic text-based adventure game developed in C++ where exploration and inventory management are the keys to success.

## 👤 Author
* **Hector Vergel**

## 🔗 Repository
You can find the source code and the latest updates here:
[https://github.com/HectorVergel/Zork_Type_Game](https://github.com/HectorVergel/Zork_Type_Game)

## 📜 License
This project is licensed under the **MIT License**. See the `LICENSE` file in the repository for more details.

---

## 🎮 Gameplay Guide

### ⚠️ Important: Case Sensitivity
The game parser is **case-sensitive**. Please follow these naming conventions:
* **Commands:** Must be in **lowercase** (e.g., `look`, `go`).
* **Directions:** Must be in **lowercase** (e.g., `north`, `south`, `east`, `west`).
* **Items & NPCs:** Must start with a **Capital Letter** (e.g., `Key`, `Amulet`, `Backpack`, `Gardener`).

### Available Commands
Use the following commands in the console to interact with the world (you can also type help to get these commands):

| Command | Description |
| :--- | :--- |
| `look` | Inspect the current room to see objects, NPCs, and exits. |
| `go (direction)` | Move in a specific direction (north, south, east, west). |
| `take (item)` | Pick up an item from the ground and add it to your inventory. |
| `drop (item)` | Remove an item from your inventory and leave it in the room. |
| `store (item) (storage)`| Put an item inside a container (e.g., a chest or a bag). |
| `talk (name)` | Initiate a conversation with a Non-Player Character (NPC). |
| `quit` | Save your progress (if applicable) and exit the game. |

### Map

[TENT]
  |
(NORTH)
   |
[CAMP] <---(WEST)--- [FOREST] ---(EAST)---> [CAVE] ---(EAST)---> [HIDEDROOM]
                      (START)                  |                  (ITEM: KEY)
                                               |
                                             (SOUTH)
                                               |
                                            [BEDROOM]
                                         (ITEM: AMULET)

---

## 🏆 How to Finish the Game (Walkthrough)

To win the game, you must satisfy the NPC's request by completing their **Quest**. Follow these steps:

1.  **Talk to the NPC:** Find the character within the map and use the `talk` command. They will ask you to retrieve the **Amulet**.
2.  **The Campsite & The Forest:** Explore near the forest to find the **Campsite**. Inside the campsite, look for the **Tent**.
3.  **Get the Backpack:** In the tent, you can find a **Backpack**. Use `take Backpack`. This item is crucial as it allows you to **store up to 4 items**.
4.  **Find the Key:** Explore the depths of the cave. You must find a specific room containing the **Key**. Use `take Key` to collect it.
5.  **Locate the Bedroom:** Navigate to the Bedroom area located inside the cave system.
6.  **Use the Key:** The **Amulet** is protected. You must have the Key in your inventory (or inside your backpack) to access the item.
7.  **Retrieve the Amulet:** Once you have access, use `take Amulet`.
8.  **Final Delivery:** Return to the NPC's location and speak to them again while carrying the Amulet to complete the quest and win the game.

---
