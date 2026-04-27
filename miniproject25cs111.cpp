#include <iostream>
#include <vector>
using namespace std;

// BASE CLASS
class User {
protected:
    string name;

public:
    User(string n) : name(n) {}
    string getName() { return name; }
};

//  ITEM CLASS
class Item {
private:
    int id;
    string name;
    float highestBid;
    string highestBidder;
    float minIncrement;

public:
    Item(int i, string n, float basePrice, float inc) {
        id = i;
        name = n;
        highestBid = basePrice;
        highestBidder = "None";
        minIncrement = inc;
    }

    void display() {
        cout << "\nID: " << id
             << " | Item: " << name
             << " | Highest Bid: " << highestBid
             << " | Bidder: " << highestBidder << endl;
    }

    bool placeBid(string bidder, float amount) {
        if (amount >= highestBid + minIncrement) {
            highestBid = amount;
            highestBidder = bidder;
            cout << "✅ Bid accepted!\n";
            return true;
        } else {
            cout << "❌ Bid too low! Minimum required: "
                 << highestBid + minIncrement << endl;
            return false;
        }
    }

    int getId() { return id; }
    string getWinner() { return highestBidder; }
};

//  BIDDER CLASS
class Bidder : public User {
public:
    Bidder(string n) : User(n) {}

    void bid(Item &item) {
        float amount;
        cout << name << ", enter your bid: ";
        cin >> amount;
        item.placeBid(name, amount);
    }
};

// ================= AUCTION SYSTEM =================
class AuctionSystem {
private:
    vector<Item> items;
    vector<Bidder> bidders;
    int itemCounter = 1;

public:

    // Add item dynamically
    void addItem() {
        string name;
        float basePrice, increment;

        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter base price: ";
        cin >> basePrice;
        cout << "Enter minimum increment: ";
        cin >> increment;

        items.push_back(Item(itemCounter++, name, basePrice, increment));
        cout << "✅ Item added successfully!\n";
    }

    // Add bidder dynamically
    void addBidder() {
        string name;
        cout << "Enter bidder name: ";
        cin >> name;

        bidders.push_back(Bidder(name));
        cout << "✅ Bidder registered!\n";
    }

    // Show items
    void showItems() {
        if (items.empty()) {
            cout << "No items available!\n";
            return;
        }

        for (auto &item : items) {
            item.display();
        }
    }

    // MULTI-PLAYER BIDDING SYSTEM
    void startAuction() {
        if (items.empty() || bidders.empty()) {
            cout << "⚠ Add items and bidders first!\n";
            return;
        }

        int itemId;
        showItems();

        cout << "\nEnter Item ID for auction: ";
        cin >> itemId;

        Item* selectedItem = nullptr;

        for (auto &item : items) {
            if (item.getId() == itemId) {
                selectedItem = &item;
                break;
            }
        }

        if (selectedItem == nullptr) {
            cout << "❌ Invalid Item ID!\n";
            return;
        }

        cout << "\n🚀 Auction Started!\n";

        bool auctionActive = true;

        while (auctionActive) {
            int skipCount = 0;

            for (auto &bidder : bidders) {
                int choice;

                cout << "\n" << bidder.getName() << "'s turn\n";
                selectedItem->display();

                cout << "1. Place Bid\n2. Skip\nChoice: ";
                cin >> choice;

                if (choice == 1) {
                    bidder.bid(*selectedItem);
                } else {
                    cout << bidder.getName() << " skipped.\n";
                    skipCount++;
                }
            }

            // End if all players skipped
            if (skipCount == bidders.size()) {
                auctionActive = false;
            }
        }

        cout << "\n🏁 Auction Ended!\n";
        cout << "Winner: " << selectedItem->getWinner() << endl;
    }

    // Menu system
    void run() {
        int choice;

        while (true) {
            cout << "\n===== AUCTION SYSTEM =====\n";
            cout << "1. Add Item\n";
            cout << "2. Add Bidder\n";
            cout << "3. Show Items\n";
            cout << "4. Start Auction\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addItem(); break;
                case 2: addBidder(); break;
                case 3: showItems(); break;
                case 4: startAuction(); break;
                case 5: return;
                default: cout << "Invalid choice!\n";
            }
        }
    }
};

// MAIN
int main() {
    AuctionSystem system;
    system.run();
    return 0;
}
