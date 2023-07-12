//deleting all the documents
db.inventory.deleteMany({})

//deleting one document
db.inventory.deleteOne({status:"K"})

//deleting many documents with condition
db.inventory.deleteMany({status:"K"})

//using remove command:
db.inventory.remove({status:"A"})

