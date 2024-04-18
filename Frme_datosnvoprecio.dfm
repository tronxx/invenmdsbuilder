object Frame_datosnvoprecio: TFrame_datosnvoprecio
  Left = 0
  Top = 0
  Width = 776
  Height = 306
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 776
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Fecha: TLabel
      Left = 8
      Top = 11
      Width = 70
      Height = 13
      Caption = 'Fecha Captura'
    end
    object Label2: TLabel
      Left = 200
      Top = 11
      Width = 41
      Height = 13
      Caption = 'Vigencia'
    end
    object Label14: TLabel
      Left = 360
      Top = 11
      Width = 53
      Height = 13
      Caption = 'Costo Neto'
    end
    object edt_fecha: TEdit
      Left = 88
      Top = 8
      Width = 100
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 0
    end
    object edt_vigencia: TEdit
      Left = 248
      Top = 8
      Width = 100
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 1
    end
    object edt_coston: TEdit
      Left = 417
      Top = 8
      Width = 100
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 2
    end
  end
  object GroupBox3: TGroupBox
    Left = 0
    Top = 170
    Width = 776
    Height = 129
    Align = alTop
    Caption = 'Mayoreo (Precios c/Iva Inc.)'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 1
    object GroupBox4: TGroupBox
      Left = 2
      Top = 15
      Width = 772
      Height = 57
      Align = alTop
      Caption = 'Actual'
      TabOrder = 0
      object Label6: TLabel
        Left = 16
        Top = 24
        Width = 33
        Height = 13
        Caption = 'Precio '
      end
      object Label9: TLabel
        Left = 184
        Top = 24
        Width = 21
        Height = 13
        Caption = 'Mub'
      end
      object Label10: TLabel
        Left = 296
        Top = 24
        Width = 20
        Height = 13
        Caption = 'Filial'
      end
      object edt_mayact: TEdit
        Left = 53
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 0
      end
      object edt_mubmayact: TEdit
        Left = 209
        Top = 20
        Width = 49
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 1
      end
      object edt_filact: TEdit
        Left = 320
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 2
      end
    end
    object GroupBox6: TGroupBox
      Left = 2
      Top = 72
      Width = 772
      Height = 55
      Align = alClient
      Caption = 'Nuevo'
      TabOrder = 1
      object Label11: TLabel
        Left = 16
        Top = 24
        Width = 33
        Height = 13
        Caption = 'Precio '
      end
      object Label12: TLabel
        Left = 184
        Top = 24
        Width = 21
        Height = 13
        Caption = 'Mub'
      end
      object Label13: TLabel
        Left = 297
        Top = 24
        Width = 20
        Height = 13
        Caption = 'Filial'
      end
      object edt_maynvo: TEdit
        Left = 53
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 0
      end
      object edt_mubmaynvo: TEdit
        Left = 209
        Top = 20
        Width = 49
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 1
      end
      object edt_filnvo: TEdit
        Left = 320
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 2
      end
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 41
    Width = 776
    Height = 129
    Align = alTop
    Caption = 'Menudeo'
    Color = clHighlight
    ParentColor = False
    TabOrder = 2
    object GroupBox5: TGroupBox
      Left = 2
      Top = 15
      Width = 772
      Height = 57
      Align = alTop
      Caption = 'Actual'
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 24
        Width = 33
        Height = 13
        Caption = 'Precio '
      end
      object Label3: TLabel
        Left = 184
        Top = 24
        Width = 21
        Height = 13
        Caption = 'Mub'
      end
      object Label4: TLabel
        Left = 266
        Top = 24
        Width = 44
        Height = 13
        Caption = 'Situacion'
      end
      object Label15: TLabel
        Left = 456
        Top = 24
        Width = 66
        Height = 13
        Caption = 'Precio Combo'
      end
      object Label26: TLabel
        Left = 658
        Top = 24
        Width = 26
        Height = 13
        Caption = 'Plazo'
      end
      object edt_pract: TEdit
        Left = 53
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 0
      end
      object edt_mubact: TEdit
        Left = 209
        Top = 20
        Width = 49
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 1
      end
      object edt_sitact: TEdit
        Left = 320
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 2
      end
      object edt_comboact: TEdit
        Left = 526
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 3
      end
      object edt_plazo: TEdit
        Left = 688
        Top = 20
        Width = 40
        Height = 21
        TabOrder = 4
      end
    end
    object GroupBox2: TGroupBox
      Left = 2
      Top = 72
      Width = 772
      Height = 55
      Align = alClient
      Caption = 'Nuevo'
      TabOrder = 1
      object Label5: TLabel
        Left = 16
        Top = 24
        Width = 33
        Height = 13
        Caption = 'Precio '
      end
      object Label7: TLabel
        Left = 184
        Top = 24
        Width = 21
        Height = 13
        Caption = 'Mub'
      end
      object Label8: TLabel
        Left = 266
        Top = 24
        Width = 44
        Height = 13
        Caption = 'Situacion'
      end
      object Label16: TLabel
        Left = 456
        Top = 24
        Width = 66
        Height = 13
        Caption = 'Precio Combo'
      end
      object Label17: TLabel
        Left = 658
        Top = 24
        Width = 26
        Height = 13
        Caption = 'Plazo'
      end
      object edt_prnvo: TEdit
        Left = 53
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 0
      end
      object edt_mubnvo: TEdit
        Left = 209
        Top = 20
        Width = 49
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 1
      end
      object edt_sitnvo: TEdit
        Left = 320
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 2
      end
      object edt_combonvo: TEdit
        Left = 526
        Top = 20
        Width = 121
        Height = 21
        TabStop = False
        ReadOnly = True
        TabOrder = 3
      end
      object edt_plazonvo: TEdit
        Left = 688
        Top = 20
        Width = 40
        Height = 21
        TabOrder = 4
      end
    end
  end
  object dts_cambios: TDataSource
    DataSet = qry_cambios
    Left = 24
    Top = 344
  end
  object qry_cambios: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select 0 as idcambio, serie as concep,  serie as precioant,'
      'serie as precionvo from movart where codigo = '#39'-xx'#39
      ''
      ' '
      ' '
      ' ')
    UpdateObject = uqry_cambios
    Left = 64
    Top = 344
  end
  object uqry_cambios: TUpdateSQL
    Left = 128
    Top = 352
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inven where codigo = :CODIGO and cia = :CIA'
      ' ')
    Left = 96
    Top = 344
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
