object DMod: TDMod
  OldCreateOrder = False
  Height = 622
  Width = 617
  object ADOConn: TADOConnection
    LoginPrompt = False
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 40
    Top = 32
  end
  object ADOdsWildCard: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from WildCard'
    Parameters = <>
    Left = 152
    Top = 32
  end
  object ADOdsTarrifs: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from TarrifRates'
    Parameters = <>
    Left = 152
    Top = 88
  end
  object ADOdsSightings: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from Sightings'
    Parameters = <>
    Left = 152
    Top = 144
  end
  object ADOdsRangers: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from Rangers'
    Parameters = <>
    Left = 152
    Top = 200
  end
  object ADOdsClientWildCards: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from ClientWildCards'
    Parameters = <>
    Left = 152
    Top = 248
  end
  object ADOdsClients: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select  * from Clients'
    Parameters = <>
    Left = 152
    Top = 304
    object ADOdsClientsClientNr: TWideStringField
      FieldName = 'ClientNr'
      Size = 7
    end
    object ADOdsClientsSurname: TWideStringField
      FieldName = 'Surname'
    end
    object ADOdsClientsInitials: TWideStringField
      FieldName = 'Initials'
      Size = 4
    end
    object ADOdsClientsSAIDNum: TWideStringField
      FieldName = 'SAIDNum'
      Size = 14
    end
    object ADOdsClientsJoinDate: TDateTimeField
      FieldName = 'JoinDate'
    end
    object ADOdsClientsAddressLine1: TWideStringField
      FieldName = 'AddressLine1'
      Size = 35
    end
    object ADOdsClientsAddressLine2: TWideStringField
      FieldName = 'AddressLine2'
      Size = 25
    end
    object ADOdsClientsCityTown: TWideStringField
      FieldName = 'CityTown'
    end
    object ADOdsClientsPostalCode: TWideStringField
      FieldName = 'PostalCode'
      Size = 5
    end
    object ADOdsClientsLoyaltyPoints: TIntegerField
      FieldName = 'LoyaltyPoints'
    end
    object ADOdsClientsWildCardNr: TWideStringField
      FieldName = 'WildCardNr'
      Size = 8
    end
  end
  object ADOdsCamptypes: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from CampTypes'
    Parameters = <>
    Left = 152
    Top = 360
  end
  object ADOdsCamps: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from Camps'
    Parameters = <>
    Left = 152
    Top = 416
  end
  object ADOdsAccTypes: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    CommandText = 'select * from AccomodationTypes'
    Parameters = <>
    Left = 152
    Top = 480
  end
  object DSWildCard: TDataSource
    DataSet = ADOdsWildCard
    Left = 264
    Top = 32
  end
  object DSTarrifs: TDataSource
    DataSet = ADOdsTarrifs
    Left = 264
    Top = 88
  end
  object DSSightings: TDataSource
    DataSet = ADOdsSightings
    Left = 264
    Top = 144
  end
  object DSRangers: TDataSource
    DataSet = ADOdsRangers
    Left = 264
    Top = 200
  end
  object DSClientWildCards: TDataSource
    DataSet = ADOdsClientWildCards
    Left = 264
    Top = 248
  end
  object DSClients: TDataSource
    DataSet = ADOdsClients
    Left = 264
    Top = 304
  end
  object DSCampTypes: TDataSource
    DataSet = ADOdsCamptypes
    Left = 264
    Top = 360
  end
  object DSCamps: TDataSource
    DataSet = ADOdsCamps
    Left = 264
    Top = 416
  end
  object DSAccTypes: TDataSource
    DataSet = ADOdsAccTypes
    Left = 264
    Top = 480
  end
  object ADOUseQuery1: TADOQuery
    Connection = ADOConn
    Parameters = <>
    Left = 424
    Top = 32
  end
  object ADOUseQuery2: TADOQuery
    Connection = ADOConn
    Parameters = <>
    Left = 424
    Top = 96
  end
  object DSQuery1: TDataSource
    DataSet = ADOUseQuery1
    Left = 512
    Top = 32
  end
  object DSQuery2: TDataSource
    DataSet = ADOUseQuery2
    Left = 512
    Top = 96
  end
  object ADOdsTemp: TADODataSet
    Connection = ADOConn
    CursorType = ctStatic
    Parameters = <>
    Left = 152
    Top = 544
  end
  object DSTemp: TDataSource
    DataSet = ADOdsTemp
    Left = 264
    Top = 544
  end
  object ADOCommand: TADOCommand
    Connection = ADOConn
    Parameters = <>
    Left = 424
    Top = 200
  end
end
