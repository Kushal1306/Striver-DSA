//updating one document
db.inventory.updateOne(
    {item:"paper"},
    {
        $set:{"size.uom":"cm",status:"P"},
        $currentDate:{lastModified:true}
    }
)

///updating many documents
db.inventory.updateMany(
    {qty:{$lt:50}},
    {
        $set:{"size.uom":"in",status:"K"},
        $currentDate:{lastModified:true}
    }
)
