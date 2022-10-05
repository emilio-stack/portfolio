//
//  Pizza_OrdersApp.swift
//  Pizza Orders
//
//  Created by Emilio on 7/10/21.
//

import SwiftUI

@main
struct Pizza_OrdersApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
