//insertting one document into colelction
db.inventory.insertOne(
    {
        item:"canvas",qty:100,tags:["cotton"],size:{h:28,w:35.5,uom:"cm"}
    }
)


//inserting multiple documents into collection

db.inventory.insertMany(
    [
        {item:"canvas1",qty:50,tags:["cotton"],size:{h:28,w:35.5,uom:"cm"}},
        {item:"canvas2",qty:90,tags:["copper"],size:{h:28,w:5.5,uom:"cm"}},
        {item:"canvas3",qty:80,tags:["zinx"],size:{h:28,w:32,uom:"cm"}}
    ]
)