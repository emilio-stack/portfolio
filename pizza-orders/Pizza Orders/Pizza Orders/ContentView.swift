//
//  ContentView.swift
//  Pizza Orders
//
//  Created by Emilio on 7/10/21.
//
// Next step is to create the UI

import SwiftUI
import CoreData

struct ContentView: View {
    @State var showOrderSheet = false
    @Environment(\.managedObjectContext) private var viewContext
    @FetchRequest(entity: Order.entity(), sortDescriptors: [], predicate: NSPredicate(format: "status != %@", Status.completed.rawValue))
    var orders: FetchedResults<Order>
    var body: some View {
        NavigationView {
            List {
                ForEach(orders) { order in
                    HStack {
                        VStack(alignment: .leading) {
                            Text("\(order.pizzaType) - \(order.numberOfSlices) slices")
                                .font(.headline)
                            Text("Table \(order.tableNumber)")
                                .font(.subheadline)
                        }
                        Spacer()
                        Button(action: {
                            updateOrder(order: order)
                        }) {
                            Text(order.orderStatus == .pending ? "Prepare" : "Complete")
                                .foregroundColor(.blue)
                        }
                    }
                    .frame(height: 50)
                }
                .onDelete { indexSet in
                    for index in indexSet {
                        viewContext.delete(orders[index])
                    }
                    do {
                        try viewContext.save()
                    } catch {
                        print(error.localizedDescription)
                    }
                }
            }
            .listStyle(PlainListStyle())
            .navigationTitle("My Orders")
            .navigationBarItems(trailing: Button(action: {showOrderSheet = true
            }, label: {
                Image(systemName: "plus.circle")
                    .imageScale(.large)
            }))
            .sheet(isPresented: $showOrderSheet) {
                OrderSheet()
            }
        }
    }
    func updateOrder(order: Order) {
        let newStatus = order.orderStatus == .pending ? Status.preparing : .completed
        viewContext.performAndWait {
            order.orderStatus = newStatus
            try? viewContext.save()
        }
    }
}



struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView().environment(\.managedObjectContext, PersistenceController.preview.container.viewContext)
    }
}
