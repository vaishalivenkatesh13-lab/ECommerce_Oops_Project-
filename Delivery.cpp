#include "Delivery.h"
#include <stdexcept>
using namespace std;

// Constructor
Delivery::Delivery() {
    deliveryID      = 0;
    deliveryStatus  = "Not Assigned";
    deliveryAddress = "";
    expectedDate    = "";
}


// ─── Assign Delivery (linked with Order) ─────────────────────────────────────
void Delivery::assignDelivery(int id, const string& address,
                              const string& date, Order& order) {
    try {
        if (id <= 0) {
            throw invalid_argument("Invalid Delivery ID.");
        }
        if (address.empty()) {
            throw invalid_argument("Delivery address cannot be empty.");
        }

        deliveryID      = id;
        deliveryAddress = address;
        expectedDate    = date;
        deliveryStatus  = "Assigned";

        cout << "  [Delivery] Delivery assigned successfully!\n";

        // Updates Order's status — Composition in action
        order.updateOrderStatus("Out for Delivery");
    }
    catch (exception& e) {
        cout << "  [Delivery Error] " << e.what() << endl;
    }
}


// ─── Update Delivery Status ──────────────────────────────────────────────────
void Delivery::updateDeliveryStatus(const string& status) {

    try {
        if (status.empty()) {
            throw invalid_argument("Status cannot be empty.");
        }
        deliveryStatus = status;
        cout << "  [Delivery] Status updated to: " << deliveryStatus << "\n";
    }
    catch (exception& e) {
        cout << "  [Delivery Error] " << e.what() << endl;
    }
}


// ─── Track Delivery ──────────────────────────────────────────────────────────
void Delivery::trackDelivery() const {
    cout << "\n  --- Delivery Details -------------\n";
    cout << "  Delivery ID    : " << deliveryID      << endl;
    cout << "  Address        : " << deliveryAddress << endl;
    cout << "  Status         : " << deliveryStatus  << endl;
    cout << "  Expected Date  : " << expectedDate    << endl;
    cout << "  ----------------------------------\n";
}
