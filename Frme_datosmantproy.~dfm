object Frame_datosmantproy: TFrame_datosmantproy
  Left = 0
  Top = 0
  Width = 580
  Height = 200
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 8
    Top = 5
    Width = 561
    Height = 188
    Caption = 'Agregar Proyeccion'
    TabOrder = 0
    object Label1: TLabel
      Left = 37
      Top = 21
      Width = 28
      Height = 13
      Caption = 'Zona:'
    end
    object Label2: TLabel
      Left = 17
      Top = 45
      Width = 47
      Height = 13
      Caption = 'SubZona:'
    end
    object Label3: TLabel
      Left = 23
      Top = 69
      Width = 40
      Height = 13
      Caption = 'Nombre:'
    end
    object lkcmb_ptovta: TDBLookupComboBox
      Left = 66
      Top = 18
      Width = 65
      Height = 21
      DropDownWidth = 200
      KeyField = 'ZONA'
      ListField = 'ZONA; NOMBRE'
      ListSource = dts_zonas
      TabOrder = 1
    end
    object DBEdit1: TDBEdit
      Left = 133
      Top = 18
      Width = 140
      Height = 21
      TabStop = False
      DataField = 'NOMBRE'
      DataSource = dts_zonas
      TabOrder = 0
    end
    object edt_subzon: TdxEdit
      Left = 66
      Top = 42
      Width = 63
      TabOrder = 2
      CharCase = ecUpperCase
      MaxLength = 50
      StoredValues = 2
    end
    object edt_nombre: TdxEdit
      Left = 66
      Top = 65
      Width = 207
      TabOrder = 3
      CharCase = ecUpperCase
      MaxLength = 50
      StoredValues = 2
    end
    object Porcentajes: TGroupBox
      Left = 294
      Top = 7
      Width = 243
      Height = 170
      Caption = 'Porcentajes'
      TabOrder = 4
      object Label4: TLabel
        Left = 10
        Top = 18
        Width = 149
        Height = 13
        Caption = '% Costo sobre Ventas Contado '
      end
      object Label5: TLabel
        Left = 10
        Top = 42
        Width = 139
        Height = 13
        Caption = '% Costo sobre Ventas Credito'
      end
      object Label6: TLabel
        Left = 8
        Top = 66
        Width = 157
        Height = 13
        Caption = '% Costo sobre Ventas FONACOT'
      end
      object Label7: TLabel
        Left = 9
        Top = 90
        Width = 130
        Height = 13
        Caption = '% Costo sobre Ventas FIDE'
      end
      object Label8: TLabel
        Left = 10
        Top = 113
        Width = 135
        Height = 13
        Caption = '% Costo sobre Ventas IMEVI'
      end
      object Label9: TLabel
        Left = 10
        Top = 137
        Width = 149
        Height = 13
        Caption = '% Costo sobre Ventas OFERTA'
      end
      object edt_conta: TdxCurrencyEdit
        Left = 171
        Top = 15
        Width = 64
        TabOrder = 0
        DecimalPlaces = 4
        DisplayFormat = '0.0000;-0.0000'
        StoredValues = 0
      end
      object edt_crd: TdxCurrencyEdit
        Left = 171
        Top = 40
        Width = 64
        TabOrder = 1
        DecimalPlaces = 4
        DisplayFormat = '0.0000;-0.0000'
        StoredValues = 0
      end
      object edt_fona: TdxCurrencyEdit
        Left = 171
        Top = 63
        Width = 64
        TabOrder = 2
        DecimalPlaces = 4
        DisplayFormat = '0.0000;-0.0000'
        StoredValues = 0
      end
      object edt_fide: TdxCurrencyEdit
        Left = 171
        Top = 87
        Width = 64
        TabOrder = 3
        DecimalPlaces = 4
        DisplayFormat = '0.0000;-0.0000'
        StoredValues = 0
      end
      object edt_imevi: TdxCurrencyEdit
        Left = 171
        Top = 111
        Width = 64
        TabOrder = 4
        DecimalPlaces = 4
        DisplayFormat = '0.0000;-0.0000'
        StoredValues = 0
      end
      object edt_oferta: TdxCurrencyEdit
        Left = 171
        Top = 135
        Width = 64
        TabOrder = 5
        DecimalPlaces = 4
        DisplayFormat = '0.0000;-0.0000'
        StoredValues = 0
      end
    end
  end
  object dts_zonas: TDataSource
    DataSet = qry_zonas
    Left = 232
    Top = 104
  end
  object qry_zonas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by zona')
    Left = 200
    Top = 104
  end
end
