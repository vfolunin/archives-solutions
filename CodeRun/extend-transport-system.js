function extendTransportSystem(EarthRoute, MoonRoute) {
    let storage = [];
    for (let Route of [EarthRoute, MoonRoute]) {
        let transfer = Route.prototype.transfer;
        Route.prototype.transfer = function(parcel) {
            transfer(parcel);
            storage.push({
                ...parcel,
                origin: parcel.destination,
                destination: "Mothership"
            });
        };
    }
    return storage;
}